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


    /*数据表示*/
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


    /****************************************************可变报头********************************************************/
    /*连接可变报头*/
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

    /*确认连接可变报头*/
    typedef struct
    {
        uint8_t Connect_Acknowledge_Flags;
        uint8_t	Connect_Return_code;

#ifdef __MQTT5_
        mqtt5_propertries	Properties;
#endif
    }Connack_VariableHeader;


    /*发布消息可变报头*/
    typedef struct
    {
        data_represent	TOPIC;
        data_represent  Packet_Identifier;
#ifdef __MQTT5_
        mqtt5_propertries	Properties;
#endif
    }Publish_VariableHeader;


    /*PUBACK –发布确认可变报头 (QoS 1)*/
    typedef struct
    {
        uint8_t	MSB;
        uint8_t	LSB;
#ifdef __MQTT5_
        uint8_t		        PUBACK_RC;
        mqtt5_propertries	Properties;
#endif

    }Puback_VariableHeader;


    /* PUBREC – 发布已接收（QoS 2第一步)*/
    typedef struct
    {
        uint8_t	MSB;
        uint8_t	LSB;
#ifdef __MQTT5_
        uint8_t		        PUBREC_RC;
        mqtt5_propertries	Properties;
#endif
    }Pubrec_VariableHeader;

    /* PUBREL – 发布释放（QoS 2第二步)*/
    typedef struct
    {
        uint8_t	MSB;
        uint8_t	LSB;
#ifdef __MQTT5_
        uint8_t		PUBREL_RC;
        mqtt5_propertries	Properties;
#endif
    }Pubrel_VariableHeader;

    /* PUBCOMP – 发布释放（QoS 2第三步)*/
    typedef struct
    {
        uint8_t	MSB;
        uint8_t	LSB;
#ifdef __MQTT5_
        uint8_t		PUBCOMP_RC;
        mqtt5_propertries	Properties;
#endif
    }Pubcomp_VariableHeader;

    /*订阅主题可变报头*/
    typedef struct
    {
        uint8_t	MSB;
        uint8_t	LSB;
#ifdef __MQTT5_
        mqtt5_propertries	Properties;
#endif
    }Subscribe_VariableHeader;

    /*订阅确认可变报头*/
    typedef struct
    {
        uint8_t MSB;
        uint8_t LSB;
#ifdef __MQTT5_
        mqtt5_propertries	Properties;
#endif
    }Suback_VariableHeader;

    /*取消订阅可变报头*/
    typedef struct
    {
        uint8_t MSB;
        uint8_t LSB;
#ifdef __MQTT5_
        mqtt5_propertries	Properties;
#endif
    }Unsubscribe_VariableHeader;

    /*取消订阅确认可变报头*/
    typedef struct
    {
        uint8_t MSB;
        uint8_t LSB;
#ifdef __MQTT5_
        mqtt5_propertries	Properties;
#endif
    }Unsuback_VariableHeader;


    /*DISCONNECT – 断开通知*/
    typedef struct
    {
        uint8_t Disconnect_RC;
        mqtt5_propertries	Properties;

    }Disconnect_VariableHeader;

    /*AUTH 可变报头 AUTH Variable Header*/
    typedef struct
    {
        uint8_t AUTH_RC;
        mqtt5_propertries	Properties;

    }AUTH_VariableHeader;


    /*********************************************************************************************************************/



    /***************************************************有效载荷************************************************************/
    /*连接报文有效载荷*/
    typedef struct
    {
        data_represent		ClientID;

#ifdef __MQTT5_
        mqtt5_propertries	Properties;
#endif

    }Connect_Payload;


    /*发布消息报文有效载荷*/
    typedef struct
    {
        encoded_string	Message;
    }Publish_Payload;


    /*订阅报文有效载荷*/
    typedef struct
    {
        encoded_string	Message;
    }Subscribe_Payload;

    /*订阅确认有效载荷*/
    typedef struct
    {
        encoded_string	Message;

    }Suback_Payload;

    /*取消订阅有效载荷*/
    typedef struct
    {
        encoded_string	Message;
    }Unsubscribe_Payload;


#ifdef __MQTT5_
    /*取消订阅确认有效载荷*/
    typedef struct
    {
        encoded_string	Message;
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
        AUTH_VariableHeader         Auth;
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

    /*MQTT 控制报文*/
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
