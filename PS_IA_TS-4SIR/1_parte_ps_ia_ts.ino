// 1 Parte da GS/PS de IA - 4SIR
// Nome:                 Rm:
//Daniel Tan            83496
//Andre Migotto         83357
//Henrique Migotto    	83605
//Joao Ribeiro        	83482
//Rafael Caetano        83581

#include <LiquidCrystal.h> 

int ledVermelho1 = 14; 
int ledVerde1 = 15; 
int ledVermelho2 = 16; 
int ledVerde2 = 17; 
int vagaLivre = 0;          
int vagaOcupada = 0;        
int cont1 = 0;
int cont2 = 0;

float tempo1; 				 
float tempo2;  				
float distancia1;			
float distancia2;			


int trig1 = 6;             
int echo1 = 7;              
int trig2 = 5;             
int echo2 = 4;           

LiquidCrystal lcd(12,11,10,9,8,3);

void setup() 
{   
	Serial.begin(9600);                 
	pinMode(ledVermelho1,OUTPUT);         
	pinMode(ledVerde1,OUTPUT);               
	pinMode(ledVermelho2,OUTPUT);      
	pinMode(ledVerde2,OUTPUT);              
	pinMode(echo1,INPUT);                  
	pinMode(trig1,OUTPUT);                      
	pinMode(echo2,INPUT);                
	pinMode(trig2,OUTPUT);                  
	lcd.begin(16,2) ;  
	digitalWrite(trig1,LOW);              
	digitalWrite(trig2,LOW);             
	delay(10);   
}

void loop(){

//calculo distancia sensor 1     

	digitalWrite(trig1, HIGH);                    
	delay(10);  
	digitalWrite(trig1, LOW);  
    
	tempo1 = pulseIn(echo1, HIGH);           
	distancia1 = tempo1 / 29.4 / 2;           
	
//calculo distancia sensor 2    

	digitalWrite(trig2, HIGH);
	delay(10);  
	digitalWrite(trig2, LOW);      
	
	tempo2 = pulseIn(echo2, HIGH);                    
	
	distancia2 = tempo2 / 29.4 / 2;                     

	if(distancia2<200){                        
		digitalWrite(ledVermelho2,HIGH);        
		digitalWrite(ledVerde2,LOW);            
		cont2 = 1;                                         
	}else{   
		digitalWrite(ledVermelho2,LOW);             
		digitalWrite(ledVerde2,HIGH);         
		cont2 = 0;                                         
	}        
	
	if(distancia1<200){                          
	digitalWrite(ledVermelho1,HIGH);           
	digitalWrite(ledVerde1,LOW);                
	cont1 = 1;                                               
	}else{   
	digitalWrite(ledVermelho1,LOW);                
	digitalWrite(ledVerde1,HIGH);               
	cont1 = 0;                                          
	}
	
	vagaOcupada = cont1+cont2;   
	vagaLivre = 2 - vagaOcupada;
	
	lcd.setCursor ( 0,0); 
	lcd.print("Vagas livres  :");  
	lcd.setCursor ( 15,0); 
	lcd.print(vagaLivre); 
	lcd.setCursor ( 0,1); 
	lcd.print("Vagas ocupadas:");  
	lcd.setCursor ( 15,1); 
	lcd.print(vagaOcupada);
	
	Serial.print("Centimetros: ");   
	Serial.print(distancia1);   
	Serial.print("        ");   
	Serial.print("Centimetros: ");   
	Serial.println(distancia2);
	
	delay(500); 
	
}
