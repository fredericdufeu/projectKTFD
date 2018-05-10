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
        IR_CHR = 0, // char
        IR_SRT = 1, // short
        IR_STR = 2, // string
        IR_URL = 3,
        IR_INT32 = 4, // int 32 bit
        IR_INT64 = 5, // long
        IR_FLT = 6, // float
        IR_DBL = 7, // double
        
        /* array */
        IR_AY_CHR = 10,
        IR_AY_SRT = 11,
        IR_AY_STR = 12,
        IR_AY_URL = 13,
        IR_AY_INT32 = 14,
        IR_AY_INT64 = 15,
        IR_AY_FLT = 16,
        IR_AY_DBL = 17,
        
        /* double array */
        IR_DAY_CHR = 20,
        IR_DAY_SRT = 21,
        IR_DAY_STR = 22,
        IR_DAY_URL = 23,
        IR_DAY_INT32 = 24,
        IR_DAY_INT64 = 25,
        IR_DAY_FLT = 26,
        IR_DAY_DBL = 27,
    };
    
    /* INOUTDATA Structure which indicates what data type input and ouput have */
    struct INOUTDATA{
        int count;
        Type *typelist;
    };
    
}


#endif /* IRDataType_h */
