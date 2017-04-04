uint8_t inByte;
uint8_t index;
uint16_t inVal;



void readCommand(){
 // put your main code here, to run repeatedly:
  if(Serial.available()){

      while(Serial.available()>0){
        inByte = Serial.read();



        if(inByte>= '0' && inByte<= '9'){
          inVal = inVal*10+inByte-48;
        }else{
          switch(index){
            case 1:
              aVal = inVal;
              break;
            case 2:
              bVal = inVal;
              break;
            case 3:
              cVal = inVal;
              break;
          }
        }

        if(inByte == 'H'){//HANDSHAKE
           Serial.print('h');
        }
        else if(inByte == 'a'){
          index = 1;
          inVal = 0; //reset inval
        }

        else if(inByte == 'b'){
          index = 2;
          inVal = 0; //reset inval
        }

        else if(inByte == 'c'){
          index = 3;
          inVal = 0; //reset inval
        }

        else if(inByte == '\n'){
          Serial.print("a: ");
          Serial.println(aVal);
          
          Serial.print("b: ");
          Serial.println(bVal);

          Serial.print("c: ");
          Serial.println(cVal);

          break;
        }

        else{
          //do nothing  
        }
      }
  }
}
