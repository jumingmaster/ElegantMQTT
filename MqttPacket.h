#ifndef _MQTT_PACKET_H
#define _MQTT_PACKET_H
#ifdef cplusplus
extern "C" {
#endif
#include "ControlPacket.h"

#define MAX_Subscribe           255
#define MAX_Client              1024

    /*utf8-string*/
    typedef struct
    {

        unsigned short  len;
        char*           msg;

    }encoded_string;


    /*���ݱ�ʾ*/
    typedef union
    {
        uint8_t  single_byte;
        uint16_t double_bytes;
        uint32_t fourth_bytes;
        uint32_t varbytes;
        encoded_string  bin_data;
        encoded_string  utf8_string;

    }data_represent;


    typedef struct 
    {
        data_represent property_length;
        struct mqtt5_propertries * next;

#ifdef MQTT_BROKER
        bool new_client;
#endif // MQTT_BROKER

    }mqtt5_propertries;


    /****************************************************�ɱ䱨ͷ********************************************************/
    /*���ӿɱ䱨ͷ*/
    typedef struct
    {
        data_represent	Protocol_Name;
        uint8_t		    Protocol_Version;
        uint8_t		    Connect_Flag;
        data_represent  Keep_Alive;
#ifdef __MQTT5_
        mqtt5_propertries	Properties;
#endif

    }Connect_VariableHeader;

    /*ȷ�����ӿɱ䱨ͷ*/
    typedef struct
    {
        uint8_t Connect_Acknowledge_Flags;
        uint8_t	Connect_Return_code;

#ifdef __MQTT5_
        mqtt5_propertries	Properties;
#endif
    }Connack_VariableHeader;


    /*������Ϣ�ɱ䱨ͷ*/
    typedef struct
    {
        data_represent	TOPIC;
        data_represent  Packet_Identifier;
#ifdef __MQTT5_
        mqtt5_propertries	Properties;
#endif
    }Publish_VariableHeader;


    /*PUBACK �C����ȷ�Ͽɱ䱨ͷ (QoS 1)*/
    typedef struct
    {
        uint8_t	MSB;
        uint8_t	LSB;
#ifdef __MQTT5_
        uint8_t		        PUBACK_RC;
        mqtt5_propertries	Properties;
#endif

    }Puback_VariableHeader;


    /* PUBREC �C �����ѽ��գ�QoS 2��һ��)*/
    typedef struct
    {
        uint8_t	MSB;
        uint8_t	LSB;
#ifdef __MQTT5_
        uint8_t		        PUBREC_RC;
        mqtt5_propertries	Properties;
#endif
    }Pubrec_VariableHeader;

    /* PUBREL �C �����ͷţ�QoS 2�ڶ���)*/
    typedef struct
    {
        uint8_t	MSB;
        uint8_t	LSB;
#ifdef __MQTT5_
        uint8_t		PUBREL_RC;
        mqtt5_propertries	Properties;
#endif
    }Pubrel_VariableHeader;

    /* PUBCOMP �C �����ͷţ�QoS 2������)*/
    typedef struct
    {
        uint8_t	MSB;
        uint8_t	LSB;
#ifdef __MQTT5_
        uint8_t		PUBCOMP_RC;
        mqtt5_propertries	Properties;
#endif
    }Pubcomp_VariableHeader;

    /*��������ɱ䱨ͷ*/
    typedef struct
    {
        uint8_t	MSB;
        uint8_t	LSB;
#ifdef __MQTT5_
        mqtt5_propertries	Properties;
#endif
    }Subscribe_VariableHeader;

    /*����ȷ�Ͽɱ䱨ͷ*/
    typedef struct
    {
        uint8_t MSB;
        uint8_t LSB;
#ifdef __MQTT5_
        mqtt5_propertries	Properties;
#endif
    }Suback_VariableHeader;

    /*ȡ�����Ŀɱ䱨ͷ*/
    typedef struct
    {
        uint8_t MSB;
        uint8_t LSB;
#ifdef __MQTT5_
        mqtt5_propertries	Properties;
#endif
    }Unsubscribe_VariableHeader;

    /*ȡ������ȷ�Ͽɱ䱨ͷ*/
    typedef struct
    {
        uint8_t MSB;
        uint8_t LSB;
#ifdef __MQTT5_
        mqtt5_propertries	Properties;
#endif
    }Unsuback_VariableHeader;


    /*DISCONNECT �C �Ͽ�֪ͨ*/
    typedef struct
    {
        uint8_t Disconnect_RC;
        mqtt5_propertries	Properties;

    }Disconnect_VariableHeader;

    /*AUTH �ɱ䱨ͷ AUTH Variable Header*/
    typedef struct
    {
        uint8_t AUTH_RC;
        mqtt5_propertries	Properties;

    }AUTH_VariableHeader;


    /*********************************************************************************************************************/



    /***************************************************��Ч�غ�************************************************************/
    /*���ӱ�����Ч�غ�*/
    typedef struct
    {
        data_represent		ClientID;

#ifdef __MQTT5_
        mqtt5_propertries	Properties;
#endif

    }Connect_Payload;


    /*������Ϣ������Ч�غ�*/
    typedef struct
    {
        encoded_string	Message;
    }Publish_Payload;


    /*���ı�����Ч�غ�*/
    typedef struct
    {
        encoded_string	Message;
    }Subscribe_Payload;

    /*����ȷ����Ч�غ�*/
    typedef struct
    {
        encoded_string	Message;

    }Suback_Payload;

    /*ȡ��������Ч�غ�*/
    typedef struct
    {
        encoded_string	Message;
    }Unsubscribe_Payload;


#ifdef __MQTT5_
    /*ȡ������ȷ����Ч�غ�*/
    typedef struct
    {
        encoded_string	Message;
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
        AUTH_VariableHeader         Auth;
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

    /*MQTT ���Ʊ���*/
    typedef struct
    {
        FixedHeader* fixed_header;
        VariableHeader* variable_header;
        Payload* payload;
    }mqtt_packet;




#ifdef cpluscplus
}
#endif
#endif // !_MQTT_PACKET_H
