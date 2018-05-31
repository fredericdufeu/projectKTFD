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
        std::cout << "Error : " << std::endl;
    }
    
    this->url = name.getParam()[1].erase(0 ,7);
    
    std::cout << this->url << std::endl;

    main();
    
    
    
    
}

IRWaveformNodeObject::~IRWaveformNodeObject()
{
    
}

void IRWaveformNodeObject::main()
{
    std::cout << "main() in IRWaveformNodeObject called!\n";
    
    this->soundfile = new SoundFile();
    readSoundFileAtPath(this->url, this->soundfile);
    std::cout << this->soundfile->numSamples << " samples are loaded. "<< std::endl;
    
   
    
    
}



void IRWaveformNodeObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    
    kNodeObject::paint(painter,option,widget);
}

void IRWaveformNodeObject::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    kNodeObject::mousePressEvent(event);
    std::cout << "IRWaveformNodeObject mouse Press event " << std::endl;
}

void IRWaveformNodeObject::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    kNodeObject::mouseMoveEvent(event);
    std::cout << "IRWaveformNodeObject mouse Move event " << std::endl;
}

void IRWaveformNodeObject::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    kNodeObject::mouseReleaseEvent(event);
    std::cout << "IRWaveformNodeObject mouse Release event " << std::endl;
}

void IRWaveformNodeObject::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    kNodeObject::mouseDoubleClickEvent(event);
    std::cout << "IRWaveformNodeObject mouse double click event " << std::endl;
}



