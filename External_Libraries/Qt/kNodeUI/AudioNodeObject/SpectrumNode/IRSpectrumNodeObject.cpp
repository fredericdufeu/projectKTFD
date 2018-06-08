//
//  IRSpectrumNodeObject.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/06/01.
//

#include "IRSpectrumNodeObject.hpp"



IRSpectrumNodeObject::IRSpectrumNodeObject(IR_Object::Name name, IR::Frame frame, IR_Data::INOUTDATA input, IR_Data::INOUTDATA output, QGraphicsScene *parentScene)
: kNodeObject(name, frame, input, output, parentScene)
{
    this->frame2 = frame;
    if(name.getParam().size() != 3) {
        std::cout << "Error : " << std::endl;
    }
    this->url = name.getParam()[1].erase(0 ,7);
    std::cout << this->url << std::endl;
    main();
}

IRSpectrumNodeObject::~IRSpectrumNodeObject()
{
    delete this->fft;
}

void IRSpectrumNodeObject::main()
{
    std::cout << "main() in IRSpectrumNodeObject called!\n";
    
    this->soundfile = new SoundFile();
    readSoundFileAtPath(this->url, this->soundfile);
    std::cout << this->soundfile->numSamples << " samples are loaded. "<< std::endl;
    
    this->fft = new IRFFT(1024, IR_FFT::FORWARD, IR_FFT::MODE::ESTIMATE, IR_FFT::WINDOW::HANNING);
    this->fft->setInput(&this->soundfile->samples[10240], true);
    this->fft->FFT();
    this->fft->cartopol();
    
}

void IRSpectrumNodeObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    kNodeObject::paint(painter,option,widget);
    
    QPen pen(isSelected()? Qt::darkRed : Qt::blue);
    pen.setColor(Qt::black);
    painter->setPen(pen);
    
    float x = this->frame2.origin.x - this->frame2.size.width/2;
    float y = this->frame2.origin.y + this->frame2.size.height/2;
    
    for(unsigned int i=0;i<this->fft->getFFTHalfSize()-1;i++){
        painter->drawLine(x+i, y-this->fft->amplitude[i]*2, x+i+1, y-this->fft->amplitude[i+1]*2);
    }
    
}

void IRSpectrumNodeObject::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    kNodeObject::mousePressEvent(event);
    std::cout << "IRSpectrumNodeObject mouse Press event " << std::endl;
}

void IRSpectrumNodeObject::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    kNodeObject::mouseMoveEvent(event);
    std::cout << "IRSpectrumNodeObject mouse Move event " << std::endl;
}

void IRSpectrumNodeObject::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    kNodeObject::mouseReleaseEvent(event);
    std::cout << "IRSpectrumNodeObject mouse Release event " << std::endl;
}

void IRSpectrumNodeObject::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    kNodeObject::mouseDoubleClickEvent(event);
    std::cout << "IRSpectrumNodeObject mouse double click event " << std::endl;
}
