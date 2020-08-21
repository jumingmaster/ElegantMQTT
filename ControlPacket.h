#ifndef CONTROLPACKET__H
#define CONTROLPACKET__H

#ifdef __cplusplus
extern "C" {
#endif
#include <inttypes.h>

#define MAX_Remaining_Length	268435455U
#define MAX_Subscribe           255


    /*连接标志 Connect Flags*/
#define	User_Name_Flag			 (uint8_t)(0x1 << 7)
#define	Password_Flag			 (uint8_t)(0x1 << 6)
#define	Will_Retain				 (uint8_t)(0x1 << 5)
#define Will_QoS1				(uint8_t)(0x01 << 3)
#define Will_QoS2				(uint8_t)(0x10 << 3)
#define Will_QoS3				(uint8_t)(0x11 << 3)




/*包含报文标识符的控制报文 Control Packets that contain a Packet Identifier*/
    enum Contain_Packet_Identifier
    {
        Identifier_CONNECT = 0,
        Identifier_CONNACK = 0,
        Identifier_PUBLISH = 1,
        Identifier_PUBACK = 1,
        Identifier_PUBREC = 1,
        Identifier_PUBREL = 1,
        Identifier_PUBCOMP = 1,
        Identifier_SUBSCRIBE = 1,
        Identifier_SUBACK = 1,
        Identifier_UNSUBSCRIBE = 1,
        Identifier_UNSUBACK = 1,
        Identifier_PINGREQ = 0,
        Identifier_PINGRESP = 0,
        Identifier_DISCONNECT = 0,
        Identifier_AUTH = 0
    };

    /*包含有效载荷的控制报文 Control Packets that contain a Payload*/
    enum Contain_Payload
    {
        Payload_CONNECT = 1,
        Payload_CONNACK = 0,
        Payload_PUBLISH,
        Payload_PUBACK = 0,
        Payload_PUBREC = 0,
        Payload_PUBREL = 0,
        Payload_PUBCOMP = 0,
        Payload_SUBSCRIBE = 1,
        Payload_SUBACK = 1,
        Payload_UNSUBSCRIBE = 1,
        Payload_UNSUBACK = 1,
        Payload_PINGREQ = 0,
        Payload_PINGRESP = 0,
        Payload_DISCONNECT = 0,
        Payload_AUTH = 0
    };

    /****************************MQTT Control Packet type******************************************/
                /*MQTT控制报文的类型*/					/*流动方向*/			/*描述*/
#define		CONNECT				(uint8_t)0x10		//客户端到服务端		客户端请求连接服务端
#define		CONNACK				(uint8_t)0x20		//服务端到客户端		连接报文确认
#define		PUBLISH				(uint8_t)0x30		//两个方向都允许		发布消息
#define		PUBACK				(uint8_t)0x40		//两个方向都允许		QoS 1 消息发布收到确认
#define		PUBREC				(uint8_t)0x50		//两个方向都允许		发布收到（保证交付第一步）
#define		PUBREL				(uint8_t)0x60		//两个方向都允许		发布释放（保证交付第二步）
#define		PUBCOMP				(uint8_t)0x70		//两个方向都允许		QoS 2 消息发布完成（保证交互第三步）
#define		SUBSCRIBE			(uint8_t)0x80		//客户端到服务端		客户端订阅请求
#define		SUBACK				(uint8_t)0x90		//服务端到客户端		订阅请求报文确认
#define		UNSUBSCRIBE			(uint8_t)0xA0		//客户端到服务端		客户端取消订阅请求
#define		UNSUBACK			(uint8_t)0xB0		//服务端到客户端		取消订阅报文确认
#define		PINGREQ				(uint8_t)0xC0		//客户端到服务端		心跳请求
#define		PINGRESP			(uint8_t)0xD0		//服务端到客户端		心跳响应
#define		DISCONNECT			(uint8_t)0xE0		//客户端到服务端		客户端断开连接
#define		AUTH				(uint8_t)0xF0		//两个方向都允许		身份认证交换
/******************************************************************************************************/

/****************************************MQTT Control Packet flag**************************************/

//固定报头第1个字节的剩余的4位 [3-0]包含每个MQTT控制报文类型特定的标志。
//如果收到非法的标志，接收者必须关闭网络连接。

/*********标志 Flags*********/
    enum Control_Packet_Flag
    {
        CONNECT_FLAG = 0x00,
        CONNACK_FLAG = 0x00,
        PUBLISH_FLAG,
        PUBACK_FLAG = 0x00,
        PUBREC_FLAG = 0x00,
        PUBREL_FLAG = 0x02,
        PUBCOMP_FLAG = 0x00,
        SUBSCRIBE_FALG = 0x02,
        SUBACK_FLAG = 0x00,
        UNSUBSCRIBE_FLAG = 0x02,
        UNSUBACK_FLAG = 0x00,
        PINGREQ_FLAG = 0x00,
        PINGRESP_FLAG = 0x00,
        DISCONNECT_FLAG = 0x00,
        AUTH_FLAG = 0x00
    };
    /*******************************************************************************************************/

    /*******************************************属性 Properties*********************************************/
    enum mqtt5_property
    {			/*Name (usage)*/			        /*Identifier*/	        /*Type*/				/*Packet / Will Properties*/

        MQTT_PROP_PAYLOAD_FORMAT_INDICATOR = 1,		/* Byte :				PUBLISH, Will Properties */		//载荷格式说明	
        MQTT_PROP_MESSAGE_EXPIRY_INTERVAL = 2,		/* 4 byte int :			PUBLISH, Will Properties */		//消息过期时间
        MQTT_PROP_CONTENT_TYPE = 3,		            /* UTF-8 string :		PUBLISH, Will Properties */		//内容类型
        MQTT_PROP_RESPONSE_TOPIC = 8,		        /* UTF-8 string :		PUBLISH, Will Properties */		//响应主题
        MQTT_PROP_CORRELATION_DATA = 9,		        /* Binary Data :		PUBLISH, Will Properties */		//相关数据
        MQTT_PROP_SUBSCRIPTION_IDENTIFIER = 11,		/* Variable byte int :	PUBLISH, SUBSCRIBE */			//定义标识符
        MQTT_PROP_SESSION_EXPIRY_INTERVAL = 17,		/* 4 byte int :			CONNECT, CONNACK, DISCONNECT */	//会话过期间隔
        MQTT_PROP_ASSIGNED_CLIENT_IDENTIFIER = 18,	/* UTF-8 string :		CONNACK */						//分配客户标识符
        MQTT_PROP_SERVER_KEEP_ALIVE = 19,		    /* 2 byte int :			CONNACK */						//服务端保活时间
        MQTT_PROP_AUTHENTICATION_METHOD = 21,		/* UTF-8 string :		CONNECT, CONNACK, AUTH */		//认证方法
        MQTT_PROP_AUTHENTICATION_DATA = 22,		    /* Binary Data :		CONNECT, CONNACK, AUTH */		//认证数据
        MQTT_PROP_REQUEST_PROBLEM_INFORMATION = 23,	/* Byte :				CONNECT */						//请求问题信息
        MQTT_PROP_WILL_DELAY_INTERVAL = 24,		    /* 4 byte int :			Will properties */				//遗嘱延时间隔
        MQTT_PROP_REQUEST_RESPONSE_INFORMATION = 25,/* Byte :				CONNECT */						//请求响应信息
        MQTT_PROP_RESPONSE_INFORMATION = 26,		/* UTF-8 string :		CONNACK */						//请求信息
        MQTT_PROP_SERVER_REFERENCE = 28,		    /* UTF-8 string :		CONNACK, DISCONNECT */			//服务端参考
        MQTT_PROP_REASON_STRING = 31,		        /* UTF-8 string :		All except Will properties */	//原因字符串
        MQTT_PROP_RECEIVE_MAXIMUM = 33,		        /* 2 byte int :			CONNECT, CONNACK */				//接收最大数量
        MQTT_PROP_TOPIC_ALIAS_MAXIMUM = 34,		    /* 2 byte int :			CONNECT, CONNACK */				//主题别名最大长度
        MQTT_PROP_TOPIC_ALIAS = 35,		            /* 2 byte int :			PUBLISH */						//主题别名
        MQTT_PROP_MAXIMUM_QOS = 36,		            /* Byte :				CONNACK */						//最大QoS
        MQTT_PROP_RETAIN_AVAILABLE = 37,		    /* Byte :				CONNACK */						//保留属性可用性
        MQTT_PROP_USER_PROPERTY = 38,		        /* UTF-8 string pair :	All */							//用户属性
        MQTT_PROP_MAXIMUM_PACKET_SIZE = 39,		    /* 4 byte int :			CONNECT, CONNACK */				//最大报文长度
        MQTT_PROP_WILDCARD_SUB_AVAILABLE = 40,		/* Byte :				CONNACK */						//通配符订阅可用性
        MQTT_PROP_SUBSCRIPTION_ID_AVAILABLE = 41,	/* Byte :				CONNACK */						//订阅标识符可用性
        MQTT_PROP_SHARED_SUB_AVAILABLE = 42,		/* Byte :				CONNACK */						//共享订阅可用性
    /*********************************************************************************************************************/
    };

    /************************************************原因码 Reason Code***************************************************/
    enum mqtt5_return_codes {
        MQTT_RC_SUCCESS = 0,						/* CONNACK, PUBACK, PUBREC, PUBREL, PUBCOMP, UNSUBACK, AUTH */
        MQTT_RC_NORMAL_DISCONNECTION = 0,			/* DISCONNECT */
        MQTT_RC_GRANTED_QOS0 = 0,					/* SUBACK */
        MQTT_RC_GRANTED_QOS1 = 1,					/* SUBACK */
        MQTT_RC_GRANTED_QOS2 = 2,					/* SUBACK */
        MQTT_RC_DISCONNECT_WITH_WILL_MSG = 4,		/* DISCONNECT */
        MQTT_RC_NO_MATCHING_SUBSCRIBERS = 16,		/* PUBACK, PUBREC */
        MQTT_RC_NO_SUBSCRIPTION_EXISTED = 17,		/* UNSUBACK */
        MQTT_RC_CONTINUE_AUTHENTICATION = 24,		/* AUTH */
        MQTT_RC_REAUTHENTICATE = 25,				/* AUTH */
        MQTT_RC_UNSPECIFIED = 128,					/* CONNACK, PUBACK, PUBREC, SUBACK, UNSUBACK, DISCONNECT */
        MQTT_RC_MALFORMED_PACKET = 129,				/* CONNACK, DISCONNECT */
        MQTT_RC_PROTOCOL_ERROR = 130,				/* DISCONNECT */
        MQTT_RC_IMPLEMENTATION_SPECIFIC = 131,		/* CONNACK, PUBACK, PUBREC, SUBACK, UNSUBACK, DISCONNECT */
        MQTT_RC_UNSUPPORTED_PROTOCOL_VERSION = 132,	/* CONNACK */
        MQTT_RC_CLIENTID_NOT_VALID = 133,			/* CONNACK */
        MQTT_RC_BAD_USERNAME_OR_PASSWORD = 134,		/* CONNACK */
        MQTT_RC_NOT_AUTHORIZED = 135,				/* CONNACK, PUBACK, PUBREC, SUBACK, UNSUBACK, DISCONNECT */
        MQTT_RC_SERVER_UNAVAILABLE = 136,			/* CONNACK */
        MQTT_RC_SERVER_BUSY = 137,					/* CONNACK, DISCONNECT */
        MQTT_RC_BANNED = 138,						/* CONNACK */
        MQTT_RC_SERVER_SHUTTING_DOWN = 139,			/* DISCONNECT */
        MQTT_RC_BAD_AUTHENTICATION_METHOD = 140,	/* CONNACK */
        MQTT_RC_KEEP_ALIVE_TIMEOUT = 141,			/* DISCONNECT */
        MQTT_RC_SESSION_TAKEN_OVER = 142,			/* DISCONNECT */
        MQTT_RC_TOPIC_FILTER_INVALID = 143,			/* SUBACK, UNSUBACK, DISCONNECT */
        MQTT_RC_TOPIC_NAME_INVALID = 144,			/* CONNACK, PUBACK, PUBREC, DISCONNECT */
        MQTT_RC_PACKET_ID_IN_USE = 145,				/* PUBACK, SUBACK, UNSUBACK */
        MQTT_RC_PACKET_ID_NOT_FOUND = 146,			/* PUBREL, PUBCOMP */
        MQTT_RC_RECEIVE_MAXIMUM_EXCEEDED = 147,		/* DISCONNECT */
        MQTT_RC_TOPIC_ALIAS_INVALID = 148,			/* DISCONNECT */
        MQTT_RC_PACKET_TOO_LARGE = 149,				/* CONNACK, PUBACK, PUBREC, DISCONNECT */
        MQTT_RC_MESSAGE_RATE_TOO_HIGH = 150,		/* DISCONNECT */
        MQTT_RC_QUOTA_EXCEEDED = 151,				/* PUBACK, PUBREC, SUBACK, DISCONNECT */
        MQTT_RC_ADMINISTRATIVE_ACTION = 152,		/* DISCONNECT */
        MQTT_RC_PAYLOAD_FORMAT_INVALID = 153,		/* CONNACK, DISCONNECT */
        MQTT_RC_RETAIN_NOT_SUPPORTED = 154,			/* CONNACK, DISCONNECT */
        MQTT_RC_QOS_NOT_SUPPORTED = 155,			/* CONNACK, DISCONNECT */
        MQTT_RC_USE_ANOTHER_SERVER = 156,			/* CONNACK, DISCONNECT */
        MQTT_RC_SERVER_MOVED = 157,					/* CONNACK, DISCONNECT */
        MQTT_RC_SHARED_SUBS_NOT_SUPPORTED = 158,	/* SUBACK, DISCONNECT */
        MQTT_RC_CONNECTION_RATE_EXCEEDED = 159,		/* CONNACK, DISCONNECT */
        MQTT_RC_MAXIMUM_CONNECT_TIME = 160,			/* DISCONNECT */
        MQTT_RC_SUBSCRIPTION_IDS_NOT_SUPPORTED = 161, /* SUBACK, DISCONNECT */
        MQTT_RC_WILDCARD_SUBS_NOT_SUPPORTED = 162,	/* SUBACK, DISCONNECT */
    };
    /*********************************************************************************************************************/

    /*可变长度*/
    typedef union
    {
        uint8_t  size_one;
        uint16_t size_two;
        uint32_t size_three;
        uint64_t size_four;

    }VAR_SIZE;

    typedef struct
    {
        VAR_SIZE len;
        char* msg;
    }UTF8_MSG;


    /****************************************************可变报头********************************************************/
    /*连接可变报头*/
    typedef struct
    {
        VAR_SIZE	Protocol_Name;
        uint8_t		Protocol_Version;
        uint8_t		Connect_Flag;
        uint8_t		Keep_Alive[2];
#ifdef __MQTT5_
        VAR_SIZE	Properties;
#endif

    }Connect_VariableHeader;

    /*确认连接可变报头*/
    typedef struct
    {
        uint8_t Connect_Acknowledge_Flags;
        uint8_t	Connect_Return_code;

        #ifdef __MQTT5_
                VAR_SIZE	Properties;
        #endif
    }Connack_VariableHeader;


    /*发布消息可变报头*/
    typedef struct
    {
        uint8_t		MSB;
        uint8_t		LSB;
        VAR_SIZE	TPIOC;
        uint8_t		Flag_MSB;
        uint8_t		Flag_LSB;
        #ifdef __MQTT5_
                VAR_SIZE	Properties;
        #endif
    }Publish_VariableHeader;


    /*PUBACK –发布确认可变报头 (QoS 1)*/
    typedef struct
    {
        uint8_t	MSB;
        uint8_t	LSB;
        #ifdef __MQTT5_
                uint8_t		PUBACK_RC;
                VAR_SIZE	PropertyLen_LSB;
        #endif

    }Puback_VariableHeader;


    /* PUBREC – 发布已接收（QoS 2第一步)*/
    typedef struct
    {
        uint8_t	MSB;
        uint8_t	LSB;
        #ifdef __MQTT5_
                uint8_t		PUBREC_RC;
                VAR_SIZE	PropertyLen;
        #endif
    }Pubrec_VariableHeader;

    /* PUBREL – 发布释放（QoS 2第二步)*/
    typedef struct
    {
        uint8_t	MSB;
        uint8_t	LSB;
        #ifdef __MQTT5_
                uint8_t		PUBREL_RC;
                VAR_SIZE	PropertyLen;
        #endif
    }Pubrel_VariableHeader;

    /* PUBCOMP – 发布释放（QoS 2第三步)*/
    typedef struct
    {
        uint8_t	MSB;
        uint8_t	LSB;
        #ifdef __MQTT5_
                uint8_t		PUBCOMP_RC;
                VAR_SIZE	PropertyLen;
        #endif
    }Pubcomp_VariableHeader;

    /*订阅主题可变报头*/
    typedef struct
    {
        uint8_t	MSB;
        uint8_t	LSB;
        #ifdef __MQTT5_
            VAR_SIZE	PropertyLen;
        #endif
    }Subscribe_VariableHeader;

    /*订阅确认可变报头*/
    typedef struct
    {
        uint8_t MSB;
        uint8_t LSB;

    }Suback_VariableHeader;

    /*取消订阅可变报头*/
    typedef struct
    {
        uint8_t MSB;
        uint8_t LSB;
        #ifdef __MQTT5_
            VAR_SIZE	PropertyLen;
        #endif
    }Unsubscribe_VariableHeader;

    /*取消订阅确认可变报头*/
    typedef struct
    {
        uint8_t MSB;
        uint8_t LSB;
        #ifdef __MQTT5_
            VAR_SIZE	PropertyLen;
        #endif

    }Unsuback_VariableHeader;

#ifdef __MQTT5_
    /*DISCONNECT – 断开通知*/
    typedef struct
    {
        uint8_t Disconnect_RC;       
        VAR_SIZE	PropertyLen;

    }Disconnect_VariableHeader;

    /*AUTH 可变报头 AUTH Variable Header*/
    typedef struct
    {
        uint8_t AUTH_RC;
        VAR_SIZE	PropertyLen;

    }AUTH_VariableHeader;
#endif

    /*********************************************************************************************************************/



    /***************************************************有效载荷************************************************************/
    /*连接报文有效载荷*/
    typedef struct
    {
        UTF8_MSG		ClientID;

        #ifdef __MQTT5_
                VAR_SIZE	Will_Properties;
        #endif

        UTF8_MSG		Will_Topic;
        void*           Will_Payload;
        UTF8_MSG		User_Name;
        void*           Password;

    }Connect_Payload;


    /*发布消息报文有效载荷*/
    typedef struct
    {
        UTF8_MSG	Message;
    }Publish_Payload;


    /*订阅报文有效载荷*/
    typedef struct
    {
        uint8_t	MSB;
        uint8_t	LSB;
        char*   Topic_Filter;

    }Subscribe_Payload;

    /*订阅确认有效载荷*/
    typedef struct
    {
        uint8_t     Topic_Filter_Num;
        uint8_t*    Suback_RC;

    }Suback_Payload;

    /*取消订阅有效载荷*/
    typedef struct
    {
        uint8_t     Topic_Filter_Num;
        char*       Topic_Filter;
    }Unsubscribe_Payload;


    #ifdef __MQTT5_
    /*取消订阅确认有效载荷*/
    typedef struct
    {
        uint8_t     Topic_Filter_Num;
        uint8_t*    Unsuback_RC;
    }Unsuback_Payload;
    #endif


    /****************************************************** MQTT MSG HEADER ***********************************************************/

    /*固定报头 Fixed Header*/
    typedef struct
    {

        uint8_t					Packet_type;
        uint8_t					Packet_flag;

    }FixedHeader;

    /*可变报头 Variable Header*/
    typedef union
    {
        Connect_VariableHeader	    Connect;
        Connack_VariableHeader	    Connack;
        Publish_VariableHeader	    Publish;
        Puback_VariableHeader	    Puback;
        Pubrec_VariableHeader       Pubrec;
        Pubrel_VariableHeader       Pubrel;
        Pubcomp_VariableHeader      Pubcomp;
        Subscribe_VariableHeader    Subscribe;
        Suback_VariableHeader       Suback;
        Unsubscribe_VariableHeader  Unsubscribe;
        Unsuback_VariableHeader     Unsuback;
        #ifdef __MQTT5_
        Disconnect_VariableHeader   Disconnect;
        AUTH_VariableHeader         AUTH;
        #endif
    }VariableHeader;

    /*有效载荷 Payload*/
    typedef union
    {
        Connect_Payload     Connect;
        Publish_Payload     Publish;
        Subscribe_Payload   Subscribe;
        Suback_Payload      Suback;
        Unsubscribe_Payload Unsubscribe;
        #ifdef __MQTT5_
        Unsuback_Payload    Unsuback;
        #endif

    }Payload;

#ifdef __cplusplus
}
#endif

#endif
