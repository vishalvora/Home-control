
//v01 MQTT mosquitto smarrthings v01
//v01_01 structure changed...


//-----------------------------------------------------------------Library----------------------------------------------------
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

//-----------------------------------------------------------------Variable---------------------------------------------------
const char *topic = "room/switch/onoff";
const char *apssid = "ESPadmin";
const char *appass = "espadmin";
WiFiServer server(80);

char ssid[32];
char pass[32];
//int cmd;
WiFiClient wclient;
PubSubClient client(wclient);

int d0 = 16;
int d1 = 05;
int d2 = 04;
int d3 = 00;
int d4 = 00;
int d5 = 14;
int d6 = 12;
int d7 = 13;
int d8 = 15;
int d9 = 03;
int d10 = 00;
int d11 = 00;
int d12 =00;


//------------------------------------------------------------MQTT Declaration------------------------------------------------
//const char *mqtt_server = "test.mosquitto.org";
//const int mqtt_port = 1883;
//const char *mqtt_user = "vishalgvora@gmail.com";
//const char *mqtt_pass = "@ut0@nth0m";
const char *mqtt_client_name = "cloud mqtt"; // Client connections cant have the same connection name

//------------------------------------------------------------Function declaration--------------------------------------------


//-----wificonnect----

void wificonnect()
{
  if (WiFi.status() != WL_CONNECTED) 
  {
    Serial.print("Connecting to ");
    Serial.print(ssid);
    Serial.println("...");
    
    WiFi.begin(ssid, pass);

    if (WiFi.waitForConnectResult() != WL_CONNECTED)
      return;
    Serial.println("WiFi connected");
  }
}

void configureSM(String cmd)
{
 cmd.replace("SMssid=","");
 String ssid1 = cmd.substring(0, cmd.indexOf(",")) ;
 Serial.print(ssid1);
 String pass1 = cmd.substring(cmd.indexOf("pass=")+5);
 Serial.print(pass);
 ssid1.toCharArray(ssid,200);
 pass1.toCharArray(pass,200);
 wificonnect();
  
}


//-------switchcase---

void cmdstring(String cmd)
{
  cmd.replace("GET /?i=","");
  cmd.replace(" HTTP/1.1","");
  cmd.replace("%2B","+");
  cmd.replace("%2C",",");
  cmd.replace("%3D","=");
  cmd.replace("%27","'");
  cmd.replace("%40","@");
  Serial.print(cmd);
  
 if(cmd.equals("d0=on"))
  {
    digitalWrite(d0, HIGH); 
  }

  if(cmd.equals("d0=off"))
  {
    digitalWrite(d0, LOW);
  }

   if(cmd.equals("d1=on"))
  {
    digitalWrite(d1, HIGH); 
  }

  if(cmd.equals("d1=off"))
  {
    digitalWrite(d1, LOW);
  }

   if(cmd.equals("d2=on"))
  {
    digitalWrite(d2, HIGH); 
  }

  if(cmd.equals("d2=off"))
  {
    digitalWrite(d2, LOW);
  }

   if(cmd.equals("d3=on"))
  {
    digitalWrite(d3, HIGH); 
  }

  if(cmd.equals("d3=off"))
  {
    digitalWrite(d3, LOW);
  }

   if(cmd.equals("d4=on"))
  {
    digitalWrite(d4, HIGH); 
  }

  if(cmd.equals("d4=off"))
  {
    digitalWrite(d4, LOW);
  }

   if(cmd.equals("d5=on"))
  {
    digitalWrite(d5, HIGH); 
  }

  if(cmd.equals("d5=off"))
  {
    digitalWrite(d5, LOW);
  }

   if(cmd.equals("d6=on"))
  {
    digitalWrite(d6, HIGH); 
  }

  if(cmd.equals("d6=off"))
  {
    digitalWrite(d6, LOW);
  }

   if(cmd.equals("d7=on"))
  {
    digitalWrite(d7, HIGH); 
  }

  if(cmd.equals("d7=off"))
  {
    digitalWrite(d7, LOW);
  }

   if(cmd.equals("d8=on"))
  {
    digitalWrite(d8, HIGH); 
  }

  if(cmd.equals("d8=off"))
  {
    digitalWrite(d8, LOW);
  }

   if(cmd.equals("d9=on"))
  {
    digitalWrite(d9, HIGH); 
  }

  if(cmd.equals("d9=off"))
  {
    digitalWrite(d9, LOW);
  }

   if(cmd.equals("d10=on"))
  {
    digitalWrite(d10, HIGH); 
  }

  if(cmd.equals("d10=off"))
  {
    digitalWrite(d10, LOW);
  }

   if(cmd.equals("d11=on"))
  {
    digitalWrite(d11, HIGH); 
  }

  if(cmd.equals("d11=off"))
  {
    digitalWrite(d11, LOW);
  }

  if(cmd.equals("d12=on"))
  {
    digitalWrite(d12, HIGH); 
  }

  if(cmd.equals("d12=off"))
  {
    digitalWrite(d12, LOW);
  }
  
  if(cmd.startsWith("SMssid"))
  {
    configureSM(cmd);
  }
 
}




//----callback-----
void callback(char* topic, byte* payload, unsigned int length) 
{
  int i = 0;
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  char payl[100];
  for (i=0;i<length;i++) 
  {
  payl[i] = payload[i];
  }
    payl[i] = '\0';
    String cmd = String(payl);
    Serial.println(cmd);
    //cmd = cmd1.toInt();
    cmdstring(cmd);
    Serial.print(cmd);
}





//----Serverconnect------

void serverconnect()
{
    if (WiFi.status() == WL_CONNECTED) 
    {
      if (!client.connected()) 
      {
        Serial.println("Connecting to MQTT server");
          if (client.connect("clientID"))  
        {
          Serial.println("Connected to MQTT server");
          client.subscribe("room/switch/cmd/#");
        } 
        else 
        {
          Serial.println("Could not connect to MQTT server");   
        }
    }

   }
}

void apmode()
{
  // Check if a client has connected
  WiFiClient client = server.available();
  if (client) {
    
  

  // Read the first line of the request
  String cmd = client.readStringUntil('\r');
  Serial.println(cmd);
  client.print(cmd);
  //client.stop();
     
    cmdstring(cmd);
  
  
  
  }
}

//-----------------------------------------------------------------SETUP-----------------------------------------------------



void setup() {
  
  Serial.begin(115200);
  delay(10);
  client.setServer("test.mosquitto.org", 1883);
pinMode(d0, OUTPUT);
pinMode(d1, OUTPUT);
pinMode(d2, OUTPUT);
pinMode(d3, OUTPUT);
pinMode(d4, OUTPUT);
pinMode(d5, OUTPUT);
pinMode(d6, OUTPUT);
pinMode(d7, OUTPUT);
pinMode(d8, OUTPUT);
pinMode(d9, OUTPUT);
pinMode(d10, OUTPUT);
pinMode(d11, OUTPUT);
pinMode(d12, OUTPUT);

digitalWrite(d0, LOW);
WiFi.mode(WIFI_AP_STA);
WiFi.softAP(apssid, appass);
 server.begin();
}



//--------------------------------------------------------------------LOOP-----------------------------------------------------

void loop() 
{
  
  
  client.setCallback(callback);
  serverconnect();
 // wificonnect();
  apmode();
  if ((WiFi.status() == WL_CONNECTED) || client.connected())
  {
    //if (client.connected())
   // {
      client.loop();
   // }
  }
}



