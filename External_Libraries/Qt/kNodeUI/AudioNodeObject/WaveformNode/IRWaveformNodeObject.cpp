//
//  IRWaveformNodeObject.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/10.
//

#include "IRWaveformNodeObject.hpp"



IRWaveformNodeObject::IRWaveformNodeObject(IR_Object::Name name, IR::Frame frame, IR_Data::INOUTDATA input, IR_Data::INOUTDATA output, QGraphicsScene *parentScene)
: kNodeObject(name, frame, input, output, parentScene)
{
    
    if(name.getParam().size() != 4) {
        std::cout << "Error : num parameters wrong" << std::endl;
    }
    
    this->frame = frame;
    // this->setFrame(frame);
    
    this->url = name.getParam()[1].erase(0 ,7);
    
    // std::cout << "URL:::::" << this->url << std::endl;

    main();
    
    // setFrame
    
    
    
    
}

IRWaveformNodeObject::~IRWaveformNodeObject()
{
    
}


void IRWaveformNodeObject::setFrameOrigin(IR::Origin origin)
{
    kNodeObject::setFrameOrigin(origin);
    waveformYcenter = yt + headerDimY + 0.5 * waveformDimY;
}

// DUFEU ADD-ON
void IRWaveformNodeObject::setFrameSize(IR::Size size)
{
    kNodeObject::setFrameSize(size);
    
    waveformDimX = xdim - (leftMarginDimX + rightMarginDimX);
    if (waveformDimX < minWaveformDimX)
    {
        waveformDimX = minWaveformDimX;
        xdim = waveformDimX + leftMarginDimX + rightMarginDimX;
    }
    waveformDimY = ydim - (headerDimY + footerDimY);
    if (waveformDimY < minWaveformDimY)
    {
        waveformDimY = minWaveformDimY;
        ydim = waveformDimY + headerDimY + footerDimY;
    }
    waveformYcenter = yt + headerDimY + 0.5 * waveformDimY;
}

void IRWaveformNodeObject::main()
{
    // std::cout << "main() in IRWaveformNodeObject called!\n";
    
    this->soundfile = new SoundFile();
    readSoundFileAtPath(this->url, this->soundfile);
    // std::cout << this->soundfile->numSamples << " samples are loaded. "<< std::endl;
    // std::cout << this->soundfile->numChannels << " channels " << std::endl;
    leftMarginDimX = 40;
    rightMarginDimX = 60;
    headerDimY = 35;
    footerDimY = 20;
    
    minWaveformDimX = 10;
    minWaveformDimY = 10;
    
    // getFrame();
    
    // the 4 below should be
    
    /*
    float dimX = frame.size.width;
    float dimY = frame.size.height;
    float posX = frame.origin.x - dimX * 0.5;
    float posY = frame.origin.y - dimY * 0.5;
    */
    
    setFrameSize(frame.size);
    
    
    
    minimumSpaceBetweenRulerTicks = 10;
    minimumSpaceBetweenLabeledRulerTicks = 50;
    
    isSelectionArea = true;
    selectionStart = 100; // in samples
    selectionEnd = 450;
    
    // float x = this->frame.origin.x;
    // float y = this->frame.origin.y;
    //setPos(x, y);
    
    
    
    waveformColor = Qt::darkYellow;
    
    zoomFactor = 1.0;
    translateFactor = 0;
    
    // soundFile = file;
    
    // indexC = index;
    
    
}



void IRWaveformNodeObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // std::cout << "calling paint method????" << std::endl;
    // kNodeObject::paint(painter,option,widget);
    
    QPen pen(Qt::red);
    QBrush brush(Qt::lightGray);
    QFont font("Helvetica Neue Bold", 10);
    
    /*
    float dimX = frame.size.width;
    float dimY = frame.size.height;
    float posX = frame.origin.x - dimX * 0.5;
    float posY = frame.origin.y - dimY * 0.5;
     */
    
    // THE SELECTION AREA BACKGROUND
    
    
    if (isSelectionArea)
    {
        brush.setColor(QColor(245, 245, 255));
        painter->setBrush(brush);
        pen.setColor(Qt::transparent);
        painter->setPen(pen);
        painter->drawRect(frame.origin.x + leftMarginDimX + selectionStart + translateFactor, frame.origin.y + headerDimY, selectionEnd - selectionStart, waveformDimY);
    }
    
    
    
    // THE WAVEFORM LINES
    
    brush.setColor(Qt::lightGray);
    painter->setBrush(brush);
    pen.setColor(Qt::red);
    painter->setPen(pen);
    painter->setBrush(brush);
    
    // THIS WAS THE THING TO DO WHEN I WAS DRAWING ONE SAMPLE PER PIXEL.
    
    
    for (int i = 0; i < waveformDimX; i++)
    {
        int index = i - translateFactor;
        if (index >= 0 && index < soundfile->numSamples)
            painter->drawLine(xl + i + leftMarginDimX, waveformYcenter, xl + i + leftMarginDimX, waveformYcenter + soundfile->samples[index] * waveformDimY * 0.5);
    }
    
    // NOW REPAINT THE SELECTION AREA
    
    if (isSelectionArea)
    {
        
        pen.setColor(Qt::black);
        painter->setPen(pen);
        
        for (int i = 0; i < waveformDimX; i++)
        {
            
            int index = i - translateFactor;
            if (index >= selectionStart && index < selectionEnd)
                painter->drawLine(xl + i + leftMarginDimX, waveformYcenter, xl + i + leftMarginDimX, waveformYcenter + soundfile->samples[index] * waveformDimY * 0.5);
            
        }

    }
    
    
    // NOW, ACCORDING TO THE ZOOM FACTOR, I WILL FIND MAX VALS ETC...
    
    // FIRST, WHAT IS THE STARTING FRAME?
    
    /*
     long numSamplesPerPixel = static_cast<long>(zoomFactor);
     if (numSamplesPerPixel < 1)
     numSamplesPerPixel = 1;
     
     for (long i = 0; i < dimX; i++)
     {
     long firstIndex = (i - translateFactor) * numSamplesPerPixel;
     bool wasSomething = false;
     double min = 0.0;
     double max = 0.0;
     for (long j = firstIndex; j < firstIndex + numSamplesPerPixel; j++)
     {
     if (j >= 0 && j < soundFile->numSamples)
     {
     wasSomething = true;
     if (soundFile->samples[j] < min)
     min = soundFile->samples[j];
     if (soundFile->samples[j] > max)
     max = soundFile->samples[j];
     }
     }
     if (wasSomething)
     painter->drawLine(i, dimY * 0.5 + min * dimY * 0.5, i, dimY * 0.5 + max * dimY * 0.5);
     }
     
     */
    
    
    // IF ZOOM FACTOR = 10, THEN I HAVE 10 SAMPLES PER PIXEL. SO I NEED TO FIND THE MIN AND MAX FOR THESE...
    
    // THIS IS NOT TRIVIAL, BUT NOT TOO DIFFICULT. I WILL SUCCEED.
    
    
    // NOW, LET US MAKE A BASIC RULER WITH VALUES IN SAMPLES
    
    // FIRST, LET US MAKE AN ACTUAL FRAME
    
    
    
    // std::cout << "PAINTING " << indexC << std::endl;
    // std::cout << "PAINTING " << soundFile->path << std::endl;
    
    
    
    // THE WAVEFORM RECTANGLE FILL
    
    pen.setColor(Qt::transparent);
    painter->setPen(pen);
    if (isSelected())
        brush.setColor(Qt::blue);
    else
        brush.setColor(Qt::lightGray);
    painter->setBrush(brush);
    painter->drawRect(xl, yt, leftMarginDimX, ydim); // left margin
    painter->drawRect(xl, yt, xdim, headerDimY); // header
    painter->drawRect(xr - rightMarginDimX, yt, rightMarginDimX, ydim); // right margin
    painter->drawRect(xl, yb - footerDimY, xdim, footerDimY); // footer
    
    // THE TEXT IN THE HEADER
    
    // 1) THE FILE PATH
    
    QString text = QString::fromStdString(url);
    
    pen.setColor(Qt::black);
    painter->setPen(pen);
    brush.setColor(Qt::black);
    painter->setBrush(brush);
    font.setFamily("Helvetica");
    font.setPointSize(10);
    painter->setFont(font);
    painter->drawText(xl + leftMarginDimX, yt + headerDimY - 2 - 20, text);
    
    // 2) THE FILE INFO
    
    std::string string = "";
    
    string.append(std::to_string(soundfile->numChannels));
    string.append(" channel");
    if (soundfile->numChannels > 1)
        string.append("s");
    string.append(", ");
    string.append("sample rate: ");
    string.append(std::to_string(soundfile->samplingRate));
    string.append(" Hz, ");
    string.append(std::to_string(static_cast<double>(soundfile->numSamples) / soundfile->samplingRate));
    string.append(" sec.");
    
    
    // text = QString::fromStdString(std::to_string(soundFile->numChannels));
    
   text = QString::fromStdString(string);
   painter->drawText(xl + leftMarginDimX, yt + headerDimY - 2 - 5, text);
    
    // See QFontMetrics to measure text:
    // https://stackoverflow.com/questions/16879070/how-to-get-the-sizes-of-the-rendered-text-on-a-qpainter
    
    // THE RULER
    
    
    // THIS IS AN INTERESTING PROBLEM - SEE TACEM FOR MORE
    
    // FIRST, HOW MUCH SPACE IS THERE AND HOW MUCH TIME IS THERE?
    
    // WHAT IS THE MINIMUM SPACE I WANT BETWEEN TWO TICKS?
    
    // WHAT IS THE MINIMUM SPACE I WATN BETWEEN TWO LABELLED TICKS?
    
    
    
    
    
    
    
    // THE SELECTION AREA STROKES
    
    
    if (isSelectionArea)
    {
        brush.setColor(Qt::transparent);
        painter->setBrush(brush);
        pen.setColor(Qt::black);
        painter->setPen(pen);
        painter->drawLine(xl + leftMarginDimX + selectionStart + translateFactor, yt + headerDimY, xl + leftMarginDimX + selectionStart + translateFactor, yt + headerDimY + waveformDimY);
        painter->drawLine(xl + leftMarginDimX + selectionEnd + translateFactor, yt + headerDimY, xl + leftMarginDimX + selectionEnd + translateFactor, yt + headerDimY + waveformDimY);
    }
    
    
    
    
    // THE WAVEFORM RECTANGLE STROKE
    
    brush.setColor(Qt::transparent);
    painter->setBrush(brush);
    pen.setColor(Qt::black);
    painter->setPen(pen);
    painter->drawRect(xl + leftMarginDimX, yt + headerDimY, waveformDimX, waveformDimY);
    
    // THE OVERALL RECTANGLE
    
    pen.setColor(Qt::black);
    painter->setPen(pen);
    painter->drawRect(xl, yt, xdim, ydim);
    
}

void IRWaveformNodeObject::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    kNodeObject::mousePressEvent(event);
    std::cout << "IRWaveformNodeObject mouse Press event " << std::endl;
    
//
//    float dimX = frame.size.width;
//    float dimY = frame.size.height;
//    float posX = frame.origin.x - dimX * 0.5;
//    float posY = frame.origin.y - dimY * 0.5;
    
    // int x, y;
    
    QPointF clickedPosition = event->scenePos();
    int clickedX = static_cast<int>(clickedPosition.x()) - xl; // relative to the object not the scene
    int clickedY = static_cast<int>(clickedPosition.y()) - yt;
    
    initialClickX = clickedX;
    initialClickY = clickedY;
    
    // posX
    
    std::cout << "clicked at: " << clickedX << ", " << clickedY << std::endl;
    
    if (clickedX > xdim - 5 && clickedY > ydim - 5)
    {
        // std::cout << "clicked in corner" << std::endl;
        clickedInCorner = true;
    }
    else
    {
        // std::cout << "clicked general mon general" << std::endl;
        clickedInCorner = false;
        
        if (clickedX <= leftMarginDimX || clickedX >= xdim - rightMarginDimX || clickedY <= headerDimY || clickedY >= ydim - footerDimY)
        {
            clickedInFrame = true;
        }
        else
        {
            clickedInFrame = false;
            
            // reset selection
            
            isSelectionArea = false;
            
            update();
        }
    }
}

void IRWaveformNodeObject::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    kNodeObject::mouseMoveEvent(event); // DO I NEED THIS INDEED?
    // std::cout << "IRWaveformNodeObject mouse Move event " << std::endl;
    
    
    
    float dimX = frame.size.width;
    float dimY = frame.size.height;
    float posX = frame.origin.x - dimX * 0.5;
    float posY = frame.origin.y - dimY * 0.5;
    
    float xdelta = event->scenePos().x() - event->lastScenePos().x();
    float ydelta = event->scenePos().y() - event->lastScenePos().y();
    
    // NOW A VOIR RATIONALLY
    
    
    if (clickedInCorner) // EXPAND / RETRACT THE SIZE OF THE OBJECT
    {
        // std::cout << "dragging from corner LOL" << std::endl;
        
        dimX += xdelta;
        dimY += ydelta;
        waveformDimX = dimX - (leftMarginDimX + rightMarginDimX);
        if (waveformDimX < minWaveformDimX)
        {
            waveformDimX = minWaveformDimX;
            dimX = waveformDimX + leftMarginDimX + rightMarginDimX;
        }
        waveformDimY = dimY - (headerDimY + footerDimY);
        if (waveformDimY < minWaveformDimY)
        {
            waveformDimY = minWaveformDimY;
            dimY = waveformDimY + headerDimY + footerDimY;
        }
        waveformYcenter = posY + headerDimY + 0.5 * waveformDimY;
        
        // but I need to set the frame, here
        
        // setOrigin();
        
        // setFrameSize();
        
        /*
        frame.origin.x = posX + dimX * 0.5;
        frame.origin.y = posY + dimY * 0.5;
        
        frame.size.width = dimX;
        frame.size.height = dimY;
        
        setFrameSize(frame);
         */
        
        boundingRect();
        shape();
        update();
        scene()->update();
    }
    else if (clickedInFrame) // RELOCATE THE OBJECT
    {
        // std::cout << "mouse delta: " << xdelta << ", " << ydelta << std::endl;
        // moveBy(xdelta, ydelta); // THIS ALONE WORKS GREAT.
        
        
        
        
        /*
        IR::Origin neworigin;
        neworigin.x = frame.origin.x + xdelta;
        neworigin.y = frame.origin.y + ydelta;
        setFrameOrigin(neworigin);
        */
         
        /*
        boundingRect();
        shape();
        update();
        scene()->update();
         */
        
        // OK, BUT DON'T FORGET TO SET THE FRAME POS...!!!
        /*
        
        
        frame.origin.x = scenePos().x() - dimX * 0.5;
        frame.origin.y = scenePos().y() - dimY * 0.5;
        
        setFrameSize(frame);
        
        // posX = frame.origin.x - dimX * 0.5;
        // posY = frame.origin.y - dimY * 0.5;
        
        boundingRect();
        shape();
        update();
        scene()->update();
         */
        
        
    }
    else // CLICKED IN THE WAVEFORM SPACE: TRANSLATE, ZOOM, OR SELECT (THE DEFAULT)
    {
        // std::cout << "moving on item" << std::endl;
        
        // *** EXAMPLE 1: SIMPLY MOVE THE CONTAINER
        
        // moveBy(event->scenePos().x() - event->lastScenePos().x(), event->scenePos().y() - event->lastScenePos().y());
        
        // *** NOW, ZOOM OUT.
        
        
        if (event->modifiers() & Qt::ShiftModifier)
        {
            // JUST TRANSLATE
            translateFactor += event->scenePos().x() - event->lastScenePos().x();
            // std::cout << "translateFactor is now: " << translateFactor << std::endl;
            update();
        }
        else if (event->modifiers() & Qt::ControlModifier)
        {
            // std::cout << "control modifier, yeah" << std::endl;
            // ZOOM, WHATEVER THIS MEANS
            
            zoomFactor += (event->scenePos().x() - event->lastScenePos().x()) * 2.0; // behaviour and value to of course LOL!!! - NOTE - 2.0 USED FOR VERY LARGE FILE (55 MIN)
            // std::cout << "zoomFactor is now: " << zoomFactor << std::endl;
            update();
        }
        else
        {
            // CHANGE SELECTION AREA
            
            // isSelectionArea = true;
            
            QPointF clickedPosition = event->scenePos();
            int clickedX = static_cast<int>(clickedPosition.x()) - pos().x(); // relative to the object not the scene
            int clickedY = static_cast<int>(clickedPosition.y()) - pos().y();
            
            long origin = initialClickX - leftMarginDimX + translateFactor;
            long destination = clickedX - leftMarginDimX + translateFactor;
            
            if (origin == destination)
            {
                isSelectionArea = false;
            }
            else if (origin < destination)
            {
                isSelectionArea = true;
                selectionStart = origin;
                selectionEnd = destination;
            }
            else
            {
                isSelectionArea = true;
                selectionStart = destination;
                selectionEnd = origin;
            }
            
            update();
        }
    }
}

void IRWaveformNodeObject::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    kNodeObject::mouseReleaseEvent(event);
    std::cout << "IRWaveformNodeObject mouse Release event " << std::endl;
    
    
    IR::Origin neworigin;
    
    std::cout << "frame.origin: " << frame.origin.x << ", " << frame.origin.y << std::endl;
    neworigin.x = pos().x() + frame.origin.x;
    neworigin.y = pos().y() + frame.origin.y;
    setFrameOrigin(neworigin);
    setX(0);
    setY(0);
    
    std::cout << "frame.origin now: " << frame.origin.x << ", " << frame.origin.y << std::endl;
    
    update();
    
    
}

void IRWaveformNodeObject::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    kNodeObject::mouseDoubleClickEvent(event);
    std::cout << "IRWaveformNodeObject mouse double click event " << std::endl;
}



