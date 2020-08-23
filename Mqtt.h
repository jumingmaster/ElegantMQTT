#ifndef MQTT_H
#define MQTT_H
#ifdef cplusplus
extern "C" {
#endif
#include "MqttPacket.h"

	typedef int mqtt_sock_t;

	typedef enum {
		mqtt_new = 0,
		mqtt_connected = 1,
		mqtt_disconnecting = 2,
		mqtt_active = 3,
		mqtt_connect_pending = 4,
		mqtt_connect_srv = 5,
		mqtt_disconnect_ws = 6,
		mqtt_disconnected = 7,
		mqtt_socks5_new = 8,
		mqtt_socks5_start = 9,
		mqtt_socks5_request = 10,
		mqtt_socks5_reply = 11,
		mqtt_socks5_auth_ok = 12,
		mqtt_socks5_userpass_reply = 13,
		mqtt_socks5_send_userpass = 14,
		mqtt_expiring = 15,
		mqtt_duplicate = 17,
		mqtt_disconnect_with_will = 18,
		mqtt_disused = 19, 
		mqtt_authenticating = 20,
		mqtt_reauthenticating = 21, 
	}mqtt_client_state;

	typedef struct SubscribeTopic
	{
		char* Topic;
		struct SubscribeTopic* next;

	}SubscribeTopic;



	typedef struct
	{
		mqtt_sock_t sock;
		char* id;
		char* address;
		char* username;
		char* password;
		uint16_t keepalive;
		SubscribeTopic subscribe;
		mqtt_client_state state;
		mqtt_packet packet;
		encoded_string client_id;
	}mqtt_client;
	
















#ifdef cpluscplus
}
#endif
#endif // !MQTT_H

