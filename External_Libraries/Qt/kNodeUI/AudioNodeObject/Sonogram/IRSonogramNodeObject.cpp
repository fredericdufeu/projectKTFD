//
//  IRSonogramNodeObject.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/10.
//

#include "IRSonogramNodeObject.hpp"

IRSonogramNodeObject::IRSonogramNodeObject(IR_Object::Name name, IR::Frame frame, IR_Data::INOUTDATA input, IR_Data::INOUTDATA output, QGraphicsScene *parentScene)
: kNodeObject(name,frame,input,output, parentScene)
{
    
    if(name.getParam().size() != 4) {
        std::cout << "Error : " << std::endl;
    }
    
    this->url = name.getParam()[1].erase(0 ,7);
    
    this->frame = frame;
    this->name = name;
    
    main();
}

IRSonogramNodeObject::~IRSonogramNodeObject()
{
    
}

void IRSonogramNodeObject::main()
{
    std::cout << "main() in IRSonogramNodeObject called!\n";
    
    this->soundfile = new SoundFile();
    readSoundFileAtPath(this->url, this->soundfile);
    std::cout << this->soundfile->numSamples << " samples are loaded. "<< std::endl;
    std::cout << this->soundfile->numChannels << " channels are loaded. "<< std::endl;

}

void IRSonogramNodeObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    
    kNodeObject::paint(painter,option,widget);
    
    std::cout << this->soundfile->numSamples << " Paint samples are loaded. "<< std::endl;
    std::cout << this->soundfile->numChannels << " Paint channels are loaded. "<< std::endl;
    
    std::cout << "w h = " << this->frame.size.width << " , " << this->frame.size.height << " : " << getFrameSize().size.width << " , " << getFrameSize().size.height << std::endl;

    
    std::cout << "x y = " << this->frame.origin.x << " , " << this->frame.origin.y << " : " << getFrameSize().origin.x << " , " << getFrameSize().origin.y << std::endl;

    /*
    float x = this->frame.origin.x - this->frame.size.width/2;
    float y = this->frame.origin.y - this->frame.size.height/2;
    
    QPen pen(isSelected()? Qt::darkRed : Qt::blue);
    pen.setColor(Qt::gray);
    painter->setPen(pen);
    
    QFont font = painter->font();
    int fontsize = 20;
    font.setPointSize(fontsize);
    painter->setFont(font);
    std::cout << this->frame.size.height/2 << std::endl;
    painter->drawText(QPoint(x, y+this->frame.size.height/2), "IRSonogram");
     */
    
}


void IRSonogramNodeObject::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    kNodeObject::mousePressEvent(event);
    std::cout << "IRSonogramNodeObject mouse Press event " << std::endl;
}

void IRSonogramNodeObject::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    kNodeObject::mouseMoveEvent(event);
    std::cout << "IRSonogramNodeObject mouse Move event " << std::endl;
}

void IRSonogramNodeObject::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    kNodeObject::mouseReleaseEvent(event);
    std::cout << "IRSonogramNodeObject mouse Release event " << std::endl;
}

void IRSonogramNodeObject::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    kNodeObject::mouseDoubleClickEvent(event);
    std::cout << "IRSonogramNodeObject mouse double click event " << std::endl;
}
