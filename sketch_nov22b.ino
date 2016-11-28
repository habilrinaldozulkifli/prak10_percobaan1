boolean exitProgram = 0;
String a;
String b;
String c;
int readCommandFromSerial();
 int readsisimiring();
void setup() {
  Serial.begin (9600);
  Serial.println("========= Selamat Datang di Kalkulator Sudut =========");
  Serial.println("pilih inputan:");
  Serial.println(" Panjang Sisi Miring(miring)");
  Serial.println("Panjang Sisi Depan(depan)");
  Serial.println("Panjang Sisi Samping(samping)");
  Serial.println("nilai sudut(hasil)");
  // put your setup code here, to run once:

}

void loop() {

   int command;
  while(!exitProgram)
  {
    do
    {
      Serial.print("Type Command >> ");
      while(Serial.available()==0);
      command = readCommandFromSerial();
      switch(command)
      {
        case 1: Serial.println("sisi miring = ");
                readsisimiring();
                break;
        case 2: Serial.println("sisi depan=");
                 readsisidepan();
                break;
        case 3: Serial.println("sisi samping=");
               readsisisamping();
                break;   
        case 4: Serial.print("nilai sudut = ");//erial.println(ss.toFloat());
                Serial.println(a.toFloat()); Serial.println(b.toFloat()); Serial.println(c.toFloat());  Serial.println(atan(b.toFloat()/a.toFloat())*180/3.14);
              
                break;
        default : Serial.println("Wrong Command, Please Type Again !");
                  break;
                       
      }
    } while(command == 0);
  }
  
}
      
    
    
int readCommandFromSerial()
{
  char stringFromSerial [10];
  char data;
  int command;
  int countData = 0;
  for(int i=0;i<10;i++)
  {
    stringFromSerial[i]=0;
  }
  while(true)
  {
    if(Serial.available())
    {
      data = Serial.read();
      Serial.write(data);
      if(data=='\n')
      {
        break;
      }
      else
      {
        if(data!='\r')
        {
          stringFromSerial[countData] = data;
          countData++;
        }
      }
    }
  }
  
  if (strcmp(stringFromSerial,"miring")==0)
  {
    command =1;
  }
  else if (strcmp(stringFromSerial,"depan")==0)
  {
    command = 2;
  }
  else if (strcmp(stringFromSerial,"samping")==0)
  {
    command = 3;
  }
  else if (strcmp(stringFromSerial,"hasil")==0)
  {
    command = 4;
  }
  else 
  {
    command = 0;
  }
  return command;
}
 int readsisimiring()
{
  char readsisimiring [10];
  char sm;
  int val;
  int countData = 0;
  for(int i=0;i<10;i++)
  {
    readsisimiring[i]=0;
  }
  while(true)
  {
    if(Serial.available())
    {
      sm = Serial.read ();
        c=c+sm;
      //Serial.print("nilai sisi miring =");
      Serial.write(sm);
      if(sm=='\n')
      {
        break;
      }
      else
      {
        if(sm!='\r')
        {
          readsisimiring[countData] = sm;
          countData++;
          
        }
      }
    }
  }
  sscanf(readsisimiring,"%d", &val);
  return val;
}
int readsisidepan()
{
  char readsisidepan [10];
  char sd;
  int val;
  int countData = 0;
  for(int i=0;i<10;i++)
  {
    readsisidepan[i]=0;
  }
  while(true)
  {
    if(Serial.available())
    {
      sd = Serial.read ();
        b=b+sd;
      //Serial.print("nilai sisi miring =");;
      Serial.write(sd);
      if(sd=='\n')
      {
        break;
      }
      else
      {
        if(sd!='\r')
        {
          readsisidepan[countData] = sd;
          countData++;
          
        }
      }
    }
  }
  sscanf(readsisidepan,"%d", &val);
  return val;
}
 int readsisisamping()
{
  char readsisisamping [10];
  char ss;
  int val;
  int countData = 0;
  for(int i=0;i<10;i++)
  {
    readsisisamping[i]=0;
  }
  while(true)
  {
    if(Serial.available())
    {
      ss = Serial.read ();
      a=a+ss;
      //Serial.print("nilai sisi miring =");
      Serial.write(ss);
      if(ss=='\n')
      {
        break;
      }
      else
      {
        if(ss!='\r')
        {
          readsisisamping[countData] = ss;
          countData++;
          
        }
      }
    }
  }
  sscanf(readsisisamping,"%d", &val);
  return val;
}
  // put your main code here, to run repeatedly:


