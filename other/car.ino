#define int1 10
#define int2 9
#define int3 6
#define int4 5
#define front_light 13
#define left_light 12
#define right_light 11
#define main_light 8
#define back_light 7
#define speaker 3
#define vcc_ir 4
#define left_ir A0
#define right_ir A1
#define ldr A2
char data;  
int ldrVal;


void setup() {
  pinMode(int1, OUTPUT);
  pinMode(int2, OUTPUT);
  pinMode(int3, OUTPUT);
  pinMode(int4, OUTPUT);   
  pinMode(main_light, OUTPUT);   // main light (in car) 
  pinMode(front_light, OUTPUT);  // front light 
  pinMode(back_light, OUTPUT);   // back light 
  pinMode(left_light, OUTPUT);   //side left light
  pinMode(right_light, OUTPUT);  //side right light 
  pinMode(speaker, OUTPUT);      //speaker for horn
  pinMode(vcc_ir, OUTPUT);      //speaker for horn
  pinMode(left_ir, INPUT);       // initialize Left sensor as an input
  pinMode(right_ir, INPUT);      // initialize Right sensor as an input
  pinMode(ldr, INPUT);           // initialize ldr sensor for brightness
  Serial.begin(9600);            //Set the baud rate to your Bluetooth module.
}
  
void loop() {
if(Serial.available()){
  data = Serial.read();
  Serial.println(data);
} 

ldrVal = analogRead(ldr); 
if(ldrVal <= 400){
  digitalWrite(main_light,HIGH);
  digitalWrite(front_light,HIGH);
} else {
  digitalWrite(main_light,LOW);
  digitalWrite(front_light,LOW);
}
 
if(data == 'F'){                 //move forward 
  digitalWrite(int1,HIGH);
  digitalWrite(int3,HIGH);
  digitalWrite(speaker,LOW);
  digitalWrite(left_light,LOW);
  digitalWrite(right_light,LOW);
  digitalWrite(back_light,LOW);
}
 
else if(data == 'B'){            //move reverse  
  digitalWrite(int2,HIGH);
  digitalWrite(int4,HIGH);
  digitalWrite(back_light,HIGH);
  digitalWrite(speaker,HIGH);
  digitalWrite(left_light,LOW);
  digitalWrite(right_light,LOW);
}
 
else if(data == 'L'){            //turn left  
  digitalWrite(int1,HIGH);
  digitalWrite(int4,HIGH);  
  digitalWrite(left_light,HIGH); 
  digitalWrite(right_light,LOW); 
}

else if(data == 'G'){            //turn forword left  
  digitalWrite(int1,HIGH); 
  analogWrite(int3,100);
  digitalWrite(left_light,HIGH);
  digitalWrite(right_light,LOW); 
} 

else if(data == 'H'){           //turn back left  
  digitalWrite(int2,HIGH);
  analogWrite(int4,100);
  digitalWrite(back_light,HIGH); 
  analogWrite(speaker,100);
  digitalWrite(left_light,HIGH);
  digitalWrite(right_light,LOW); 
}

else if(data == 'J'){           //turn back right  
  analogWrite(int2,100);
  digitalWrite(int4,HIGH);
  digitalWrite(back_light,HIGH);
  analogWrite(speaker,100);
  digitalWrite(right_light,HIGH);
  digitalWrite(left_light,LOW);
}

else if(data == 'I'){           //turn forword right  
  analogWrite(int1,100);
  digitalWrite(int3,HIGH); 
  digitalWrite(right_light,HIGH);
  digitalWrite(left_light,LOW);
}
 
else if(data == 'R'){           //turn right 
  digitalWrite(int3,HIGH);
  digitalWrite(int2,HIGH);
  digitalWrite(right_light,HIGH); 
  digitalWrite(left_light,LOW);
}
  
else if(data == 'W'){           //turn on front light 
  digitalWrite(front_light,HIGH); 
}
  
else if(data == 'w'){           //turn off front light
  digitalWrite(front_light,LOW); 
} 
  
else if(data == 'U'){           //turn on back light 
  digitalWrite(back_light,HIGH); 
}
  
else if(data == 'u'){           //turn off back light
  digitalWrite(back_light,LOW); 
}
 
else if(data == 'V'){           //turn on horn
  digitalWrite(speaker,HIGH); 
}
  
else if(data == 'v'){           //turn off horn
  digitalWrite(speaker,LOW); 
}
 
else if(data == 'S'){           //STOP (all motors stop) and on back light
  digitalWrite(int1,LOW); 
  digitalWrite(int2,LOW); 
  digitalWrite(int3,LOW); 
  digitalWrite(int4,LOW); 
  digitalWrite(back_light,HIGH);
  digitalWrite(left_light,LOW);
  digitalWrite(right_light,LOW);
  digitalWrite(speaker,LOW);
} 

else if(data == 'X'){         // this code for lane following 
  digitalWrite(vcc_ir,HIGH);
  int LEFT_SENSOR = digitalRead(left_ir);
  int RIGHT_SENSOR = digitalRead(right_ir); 
    
  if(RIGHT_SENSOR==0 && LEFT_SENSOR==0) {
    analogWrite(int1,100);
    analogWrite(int2,0);
    analogWrite(int3,100);       //FORWARD
    analogWrite(int4,0);
    digitalWrite(speaker,LOW);
    digitalWrite(left_light,LOW);
    digitalWrite(right_light,LOW);
    digitalWrite(back_light,LOW);
  }
  
    else if(RIGHT_SENSOR==0 && LEFT_SENSOR==1) {
    analogWrite(int1,150);
    analogWrite(int4,150);     //Move left
    digitalWrite(left_light,HIGH); 
    digitalWrite(right_light,LOW); 
    digitalWrite(int2,LOW);
    digitalWrite(int3,LOW);
  }
  
    else if(RIGHT_SENSOR==1 && LEFT_SENSOR==0) {
    analogWrite(int3,150);
    analogWrite(int2,150);     //Move right
    digitalWrite(right_light,HIGH); 
    digitalWrite(left_light,LOW);
    digitalWrite(int1,LOW);
    digitalWrite(int4,LOW);
  }
  
    else if(RIGHT_SENSOR==1 && LEFT_SENSOR==1) {
    analogWrite(int1,0); 
    analogWrite(int2,0); 
    analogWrite(int3,0); 
    analogWrite(int4,0);      //STOP
    digitalWrite(back_light, HIGH); 
    digitalWrite(left_light,LOW);
    digitalWrite(right_light,LOW);
    digitalWrite(speaker,LOW);
  }

} 

else if(data =='x'){
  digitalWrite(vcc_ir,LOW);
   digitalWrite(int1,LOW); 
  digitalWrite(int2,LOW); 
  digitalWrite(int3,LOW); 
  digitalWrite(int4,LOW); 
  digitalWrite(back_light,HIGH);
  digitalWrite(left_light,LOW);
  digitalWrite(right_light,LOW);
  digitalWrite(speaker,LOW);
}

else if(data =='D'){
  digitalWrite(vcc_ir,LOW);
   digitalWrite(int1,LOW); 
  digitalWrite(int2,LOW); 
  digitalWrite(int3,LOW); 
  digitalWrite(int4,LOW); 
  digitalWrite(back_light,LOW);
  digitalWrite(left_light,LOW);
  digitalWrite(right_light,LOW);
  digitalWrite(front_light,LOW);
  digitalWrite(main_light,LOW);
  digitalWrite(speaker,LOW);
}
}
