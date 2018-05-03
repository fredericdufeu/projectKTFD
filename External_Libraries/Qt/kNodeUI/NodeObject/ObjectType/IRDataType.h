//
//  IRDataType.h
//  NodeObjectSystem2
//
//  Created by Keitaro Takahashi on 2018/04/25.
//  Copyright © 2018 Keitaro Takahashi. All rights reserved.
//

#ifndef IRDataType_h
#define IRDataType_h

namespace IR_Data {

    enum Type
    {
        /* no data type */
        IR_NULL = -1,
        
        /* variable */
        IR_CHR = 0,
        IR_SRT = 1,
        IR_INT32 = 2,
        IR_INT64 = 3,
        IR_FLT = 4,
        IR_DBL = 5,
        
        /* array */
        IR_AY_CHR = 10,
        IR_AY_SRT = 11,
        IR_AY_INT32 = 12,
        IR_AY_INT64 = 13,
        IR_AY_FLT = 14,
        IR_AY_DBL = 15,
        
        /* double array */
        IR_DAY_CHR = 20,
        IR_DAY_SRT = 21,
        IR_DAY_INT32 = 22,
        IR_DAY_INT64 = 23,
        IR_DAY_FLT = 24,
        IR_DAY_DBL = 25,
    };
    
    /* INOUTDATA Structure which indicates what data type input and ouput have */
    struct INOUTDATA{
        int count;
        Type *typelist;
    };
    
}


#endif /* IRDataType_h */
