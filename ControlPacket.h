#ifndef CONTROLPACKET__H
#define CONTROLPACKET__H

#ifdef __cplusplus
extern "C" {
#endif
#include <inttypes.h>

#define MAX_Remaining_Length	268435455U
#define MAX_Subscribe           255


    /*���ӱ�־ Connect Flags*/
#define	User_Name_Flag			 (uint8_t)(0x1 << 7)
#define	Password_Flag			 (uint8_t)(0x1 << 6)
#define	Will_Retain				 (uint8_t)(0x1 << 5)
#define Will_QoS1				(uint8_t)(0x01 << 3)
#define Will_QoS2				(uint8_t)(0x10 << 3)
#define Will_QoS3				(uint8_t)(0x11 << 3)




/*�������ı�ʶ���Ŀ��Ʊ��� Control Packets that contain a Packet Identifier*/
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

    /*������Ч�غɵĿ��Ʊ��� Control Packets that contain a Payload*/
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
                /*MQTT���Ʊ��ĵ�����*/					/*��������*/			/*����*/
#define		CONNECT				(uint8_t)0x10		//�ͻ��˵������		�ͻ����������ӷ����
#define		CONNACK				(uint8_t)0x20		//����˵��ͻ���		���ӱ���ȷ��
#define		PUBLISH				(uint8_t)0x30		//������������		������Ϣ
#define		PUBACK				(uint8_t)0x40		//������������		QoS 1 ��Ϣ�����յ�ȷ��
#define		PUBREC				(uint8_t)0x50		//������������		�����յ�����֤������һ����
#define		PUBREL				(uint8_t)0x60		//������������		�����ͷţ���֤�����ڶ�����
#define		PUBCOMP				(uint8_t)0x70		//������������		QoS 2 ��Ϣ������ɣ���֤������������
#define		SUBSCRIBE			(uint8_t)0x80		//�ͻ��˵������		�ͻ��˶�������
#define		SUBACK				(uint8_t)0x90		//����˵��ͻ���		����������ȷ��
#define		UNSUBSCRIBE			(uint8_t)0xA0		//�ͻ��˵������		�ͻ���ȡ����������
#define		UNSUBACK			(uint8_t)0xB0		//����˵��ͻ���		ȡ�����ı���ȷ��
#define		PINGREQ				(uint8_t)0xC0		//�ͻ��˵������		��������
#define		PINGRESP			(uint8_t)0xD0		//����˵��ͻ���		������Ӧ
#define		DISCONNECT			(uint8_t)0xE0		//�ͻ��˵������		�ͻ��˶Ͽ�����
#define		AUTH				(uint8_t)0xF0		//������������		�����֤����
/******************************************************************************************************/

/****************************************MQTT Control Packet flag**************************************/

//�̶���ͷ��1���ֽڵ�ʣ���4λ [3-0]����ÿ��MQTT���Ʊ��������ض��ı�־��
//����յ��Ƿ��ı�־�������߱���ر��������ӡ�

/*********��־ Flags*********/
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

    /*******************************************���� Properties*********************************************/
    enum mqtt5_property
    {			/*Name (usage)*/			        /*Identifier*/	        /*Type*/				/*Packet / Will Properties*/

        MQTT_PROP_PAYLOAD_FORMAT_INDICATOR = 1,		/* Byte :				PUBLISH, Will Properties */		//�غɸ�ʽ˵��	
        MQTT_PROP_MESSAGE_EXPIRY_INTERVAL = 2,		/* 4 byte int :			PUBLISH, Will Properties */		//��Ϣ����ʱ��
        MQTT_PROP_CONTENT_TYPE = 3,		            /* UTF-8 string :		PUBLISH, Will Properties */		//��������
        MQTT_PROP_RESPONSE_TOPIC = 8,		        /* UTF-8 string :		PUBLISH, Will Properties */		//��Ӧ����
        MQTT_PROP_CORRELATION_DATA = 9,		        /* Binary Data :		PUBLISH, Will Properties */		//�������
        MQTT_PROP_SUBSCRIPTION_IDENTIFIER = 11,		/* Variable byte int :	PUBLISH, SUBSCRIBE */			//�����ʶ��
        MQTT_PROP_SESSION_EXPIRY_INTERVAL = 17,		/* 4 byte int :			CONNECT, CONNACK, DISCONNECT */	//�Ự���ڼ��
        MQTT_PROP_ASSIGNED_CLIENT_IDENTIFIER = 18,	/* UTF-8 string :		CONNACK */						//����ͻ���ʶ��
        MQTT_PROP_SERVER_KEEP_ALIVE = 19,		    /* 2 byte int :			CONNACK */						//����˱���ʱ��
        MQTT_PROP_AUTHENTICATION_METHOD = 21,		/* UTF-8 string :		CONNECT, CONNACK, AUTH */		//��֤����
        MQTT_PROP_AUTHENTICATION_DATA = 22,		    /* Binary Data :		CONNECT, CONNACK, AUTH */		//��֤����
        MQTT_PROP_REQUEST_PROBLEM_INFORMATION = 23,	/* Byte :				CONNECT */						//����������Ϣ
        MQTT_PROP_WILL_DELAY_INTERVAL = 24,		    /* 4 byte int :			Will properties */				//������ʱ���
        MQTT_PROP_REQUEST_RESPONSE_INFORMATION = 25,/* Byte :				CONNECT */						//������Ӧ��Ϣ
        MQTT_PROP_RESPONSE_INFORMATION = 26,		/* UTF-8 string :		CONNACK */						//������Ϣ
        MQTT_PROP_SERVER_REFERENCE = 28,		    /* UTF-8 string :		CONNACK, DISCONNECT */			//����˲ο�
        MQTT_PROP_REASON_STRING = 31,		        /* UTF-8 string :		All except Will properties */	//ԭ���ַ���
        MQTT_PROP_RECEIVE_MAXIMUM = 33,		        /* 2 byte int :			CONNECT, CONNACK */				//�����������
        MQTT_PROP_TOPIC_ALIAS_MAXIMUM = 34,		    /* 2 byte int :			CONNECT, CONNACK */				//���������󳤶�
        MQTT_PROP_TOPIC_ALIAS = 35,		            /* 2 byte int :			PUBLISH */						//�������
        MQTT_PROP_MAXIMUM_QOS = 36,		            /* Byte :				CONNACK */						//���QoS
        MQTT_PROP_RETAIN_AVAILABLE = 37,		    /* Byte :				CONNACK */						//�������Կ�����
        MQTT_PROP_USER_PROPERTY = 38,		        /* UTF-8 string pair :	All */							//�û�����
        MQTT_PROP_MAXIMUM_PACKET_SIZE = 39,		    /* 4 byte int :			CONNECT, CONNACK */				//����ĳ���
        MQTT_PROP_WILDCARD_SUB_AVAILABLE = 40,		/* Byte :				CONNACK */						//ͨ������Ŀ�����
        MQTT_PROP_SUBSCRIPTION_ID_AVAILABLE = 41,	/* Byte :				CONNACK */						//���ı�ʶ��������
        MQTT_PROP_SHARED_SUB_AVAILABLE = 42,		/* Byte :				CONNACK */						//�����Ŀ�����
    /*********************************************************************************************************************/
    };

    /************************************************ԭ���� Reason Code***************************************************/
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

    /*�ɱ䳤��*/
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


    /****************************************************�ɱ䱨ͷ********************************************************/
    /*���ӿɱ䱨ͷ*/
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

    /*ȷ�����ӿɱ䱨ͷ*/
    typedef struct
    {
        uint8_t Connect_Acknowledge_Flags;
        uint8_t	Connect_Return_code;

        #ifdef __MQTT5_
                VAR_SIZE	Properties;
        #endif
    }Connack_VariableHeader;


    /*������Ϣ�ɱ䱨ͷ*/
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


    /*PUBACK �C����ȷ�Ͽɱ䱨ͷ (QoS 1)*/
    typedef struct
    {
        uint8_t	MSB;
        uint8_t	LSB;
        #ifdef __MQTT5_
                uint8_t		PUBACK_RC;
                VAR_SIZE	PropertyLen_LSB;
        #endif

    }Puback_VariableHeader;


    /* PUBREC �C �����ѽ��գ�QoS 2��һ��)*/
    typedef struct
    {
        uint8_t	MSB;
        uint8_t	LSB;
        #ifdef __MQTT5_
                uint8_t		PUBREC_RC;
                VAR_SIZE	PropertyLen;
        #endif
    }Pubrec_VariableHeader;

    /* PUBREL �C �����ͷţ�QoS 2�ڶ���)*/
    typedef struct
    {
        uint8_t	MSB;
        uint8_t	LSB;
        #ifdef __MQTT5_
                uint8_t		PUBREL_RC;
                VAR_SIZE	PropertyLen;
        #endif
    }Pubrel_VariableHeader;

    /* PUBCOMP �C �����ͷţ�QoS 2������)*/
    typedef struct
    {
        uint8_t	MSB;
        uint8_t	LSB;
        #ifdef __MQTT5_
                uint8_t		PUBCOMP_RC;
                VAR_SIZE	PropertyLen;
        #endif
    }Pubcomp_VariableHeader;

    /*��������ɱ䱨ͷ*/
    typedef struct
    {
        uint8_t	MSB;
        uint8_t	LSB;
        #ifdef __MQTT5_
            VAR_SIZE	PropertyLen;
        #endif
    }Subscribe_VariableHeader;

    /*����ȷ�Ͽɱ䱨ͷ*/
    typedef struct
    {
        uint8_t MSB;
        uint8_t LSB;

    }Suback_VariableHeader;

    /*ȡ�����Ŀɱ䱨ͷ*/
    typedef struct
    {
        uint8_t MSB;
        uint8_t LSB;
        #ifdef __MQTT5_
            VAR_SIZE	PropertyLen;
        #endif
    }Unsubscribe_VariableHeader;

    /*ȡ������ȷ�Ͽɱ䱨ͷ*/
    typedef struct
    {
        uint8_t MSB;
        uint8_t LSB;
        #ifdef __MQTT5_
            VAR_SIZE	PropertyLen;
        #endif

    }Unsuback_VariableHeader;

#ifdef __MQTT5_
    /*DISCONNECT �C �Ͽ�֪ͨ*/
    typedef struct
    {
        uint8_t Disconnect_RC;       
        VAR_SIZE	PropertyLen;

    }Disconnect_VariableHeader;

    /*AUTH �ɱ䱨ͷ AUTH Variable Header*/
    typedef struct
    {
        uint8_t AUTH_RC;
        VAR_SIZE	PropertyLen;

    }AUTH_VariableHeader;
#endif

    /*********************************************************************************************************************/



    /***************************************************��Ч�غ�************************************************************/
    /*���ӱ�����Ч�غ�*/
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


    /*������Ϣ������Ч�غ�*/
    typedef struct
    {
        UTF8_MSG	Message;
    }Publish_Payload;


    /*���ı�����Ч�غ�*/
    typedef struct
    {
        uint8_t	MSB;
        uint8_t	LSB;
        char*   Topic_Filter;

    }Subscribe_Payload;

    /*����ȷ����Ч�غ�*/
    typedef struct
    {
        uint8_t     Topic_Filter_Num;
        uint8_t*    Suback_RC;

    }Suback_Payload;

    /*ȡ��������Ч�غ�*/
    typedef struct
    {
        uint8_t     Topic_Filter_Num;
        char*       Topic_Filter;
    }Unsubscribe_Payload;


    #ifdef __MQTT5_
    /*ȡ������ȷ����Ч�غ�*/
    typedef struct
    {
        uint8_t     Topic_Filter_Num;
        uint8_t*    Unsuback_RC;
    }Unsuback_Payload;
    #endif


    /****************************************************** MQTT MSG HEADER ***********************************************************/

    /*�̶���ͷ Fixed Header*/
    typedef struct
    {

        uint8_t					Packet_type;
        uint8_t					Packet_flag;

    }FixedHeader;

    /*�ɱ䱨ͷ Variable Header*/
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

    /*��Ч�غ� Payload*/
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
