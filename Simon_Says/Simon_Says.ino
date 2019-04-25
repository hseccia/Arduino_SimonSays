//Authors: Hannah Seccia and Solomon Hatchett
//Description: Simon Says Arduino game
//Date: April 18, 2019

#include <LiquidCrystal.h>
LiquidCrystal lcd(A4,A5,A0,A1,A2,A3);

int Blue = 8;
int Red = 9;
int Yellow = 10;
int Green = 11;
int led;
int Simon[50];
int simonCount = 0;
int simonCorrectCount = 0;
bool buttonNotPressed = true;

int buttonPin = 4;
int buttonPin2 = 5;
int buttonPin3 = 6;
int buttonPin4= 7;


int buzzer = 12;


int score=0;
int highscore=0;



void setup() 
{
  // put your setup code here, to run once:
  lcd.begin(16,2);
 
  
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);

  pinMode(buzzer, INPUT);
  
  pinMode(Blue, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(Yellow, OUTPUT);
  pinMode(Green, OUTPUT);
  Serial.begin(9600);
  theme();
  
  //lcd.print(highscore);
}

void scoreboard()
{ 

  Serial.println("score here");
////////////////////////////////////////////////////////  
  if(score>highscore)
  {
     highscore=score;
  }
////////////////////////////////////////////////////////
   lcd.setCursor(0,0);
   lcd.print("HIGH SCORE: ");
   lcd.print(highscore);
   lcd.setCursor(0,1);
   lcd.print("SCORE: ");
   lcd.print(score);
   simonCorrectCount = 0;
   gamestart();
////////////////////////////////////////////////////////

}

void theme()                                  //plays the zelda theme
{
 
  tone(buzzer, 440);
  delay(500);
  noTone(buzzer);
  tone(buzzer, 329);
  delay(1000);
  noTone(buzzer);
  delay(300);
  
  tone(buzzer, 440);
  delay(500);
  noTone(buzzer);
  delay(300);
  
  tone(buzzer, 440);
  delay(300);
  noTone(buzzer);
  tone(buzzer, 493);
  delay(300);
  noTone(buzzer);
  tone(buzzer, 523);
  delay(300);
  noTone(buzzer);
  tone(buzzer, 587);
  delay(300);
  noTone(buzzer);
  tone(buzzer, 659);
  delay(500);
  noTone(buzzer);
  delay(300);
  
  tone(buzzer, 659);
  delay(500);
  noTone(buzzer);
  tone(buzzer, 659);
  delay(300);
  noTone(buzzer);
  tone(buzzer, 698);
  delay(300);
  noTone(buzzer);
  tone(buzzer, 783);
  delay(300);
  noTone(buzzer);
  tone(buzzer, 880);
  delay(500);
  noTone(buzzer);
  delay(300);

  tone(buzzer, 880);
  delay(500);
  noTone(buzzer);
  tone(buzzer, 880);
  delay(300);
  noTone(buzzer);
  tone(buzzer, 783);
  delay(300);
  noTone(buzzer);
  tone(buzzer, 698);
  delay(400);
  noTone(buzzer);
  delay(300);

  
  tone(buzzer, 783);
  delay(300);
  noTone(buzzer);
  delay(300);
  
  tone(buzzer, 689);
  delay(300);
  noTone(buzzer);
  tone(buzzer, 659);
  delay(500);
  noTone(buzzer);
  delay(300);

  tone(buzzer, 659);
  delay(500);
  noTone(buzzer);
  delay(200);
  tone(buzzer, 587);
  delay(300);
  noTone(buzzer);
  tone(buzzer, 587);
  delay(300);
  noTone(buzzer);
  tone(buzzer, 659);
  delay(300);
  noTone(buzzer);
  delay(300);
  tone(buzzer, 698);
  delay(500);
  noTone(buzzer);
  delay(300);
  
  tone(buzzer, 659);
  delay(300);
  noTone(buzzer);
  tone(buzzer, 587);
  delay(300);
  noTone(buzzer);
  delay(200);
  tone(buzzer, 523);
  delay(300);
  noTone(buzzer);
  tone(buzzer, 523);
  delay(300);
  noTone(buzzer);
  tone(buzzer, 587);
  delay(300);
  noTone(buzzer);
  delay(300);
  tone(buzzer, 659);
  delay(500);
  noTone(buzzer);
  delay(300);

  tone(buzzer, 587);
  delay(300);
  noTone(buzzer);
  tone(buzzer, 523);
  delay(300);
  noTone(buzzer);
  delay(200);
  tone(buzzer, 493);
  delay(300);
  noTone(buzzer);
  tone(buzzer, 493);
  delay(300);
  noTone(buzzer);
  tone(buzzer, 523);
  delay(300);
  noTone(buzzer);
  delay(300);
  tone(buzzer, 587);
  delay(500);
  noTone(buzzer);
  delay(300);

  tone(buzzer, 698);
  delay(500);
  noTone(buzzer);
  delay(200);
  tone(buzzer, 659);
  delay(300);
  noTone(buzzer);
  tone(buzzer, 329);
  delay(3000);
  noTone(buzzer);
  delay(1000);
 
}

void gamestart()
{

    nextLightGenerate();  
   
////////////////////////////////////////////////////////////////////////////////////////////////////
}

void nextLightGenerate()
{ 
  
  
    
  if (simonCount == 0)
  { 
    
    Serial.println("goin 0");
    Simon[simonCount] = random(8,12);
    digitalWrite(Simon[simonCount], HIGH);
    delay(500);
    digitalWrite(Simon[simonCount], LOW);
    delay(1000);
    buttons();
    
  }
  
  if (simonCount > 0)
  {

    //Serial.println(simonCount);
    Serial.println("goin for before ");

    Simon[simonCount] = random(8,12);

    //Serial.println(Simon[simonCount]);
    
    for (int i = 0; i < simonCount+1; i++)
    {
      Serial.println(i);
      digitalWrite(Simon[i], HIGH);
      delay(1000);
      digitalWrite(Simon[i], LOW);
      delay(1000);

    }

      
      buttonNotPressed = true;
      buttons();
    
  } 
  
}

void loop() 
{
  scoreboard();
}



 


void buttons()
{
//////////////////////////////////////////////////////////////////////////////////////////
  while (buttonNotPressed)
  {

      

//////////////////////////////////////////////////////////////////////////////////////

      if(digitalRead(buttonPin) == HIGH)
      {
        led = Blue;
        
        
        Serial.println("yes1");
        
        if (led == Simon[simonCorrectCount])
        {
          Serial.println("Right One");
          tone(buzzer, 1000);
          delay(400);
          noTone(buzzer);
          Serial.println(" Hit ");
          digitalWrite(led, HIGH);
          delay(1000);
          digitalWrite(led, LOW);
          delay(1000);
          simonCorrectCount++;
          
        }
        else if (led != Simon[simonCorrectCount])
        {
          tone(buzzer, 100);
          Serial.println("wrong1");
          delay(400);
          noTone(buzzer);

          gameover();
          
        }
        
      }
      
      else if (digitalRead(buttonPin) == LOW)
      {

        //Serial.println("running");
        
       
        if (simonCount == 0 && simonCorrectCount == 1)
        {
           Serial.println("Passed");
           simonCount++;
           score++;
           buttonNotPressed = false;
           scoreboard();  
         }
         else if (simonCount != 0 && simonCorrectCount == simonCount+1)
         {
           Serial.println("Passed");
           simonCount++;
           score++;
           buttonNotPressed = false;
           scoreboard();
         }
         else if (simonCount != 0 && simonCorrectCount != simonCount+1)
         {
          
         }
         
        
      }


      if(digitalRead(buttonPin2) == HIGH)
      {
        led = Red;
        
        
        Serial.println("yes2");
        
        if (led == Simon[simonCorrectCount])
        {
          Serial.println("Right One");
          tone(buzzer, 1000);
          delay(400);
          noTone(buzzer);
          Serial.println(" Hit ");
          digitalWrite(led, HIGH);
          delay(1000);
          digitalWrite(led, LOW);
          delay(1000);
          simonCorrectCount++;
          
        }
        else if (led != Simon[simonCorrectCount])
        {
          tone(buzzer, 100);
          Serial.println("wrong2");
          noTone(buzzer);

          gameover();
          
        }
        
      }
      
      else if (digitalRead(buttonPin2) == LOW)
      {

        //Serial.println("running");
        
       
        if (simonCount == 0 && simonCorrectCount == 1)
        {
           Serial.println("Passed");
           simonCount++;
           score++;
           buttonNotPressed = false;
           scoreboard();  
         }
         else if (simonCount != 0 && simonCorrectCount == simonCount+1)
         {
           Serial.println("Passed");
           simonCount++;
           score++;
           buttonNotPressed = false;
           scoreboard();
         }
         else if (simonCount != 0 && simonCorrectCount != simonCount+1)
         {
          
         }
         
        
      }


   if(digitalRead(buttonPin3) == HIGH)
      {
        led = Yellow;
        
        
        Serial.println("yes3");
        
        if (led == Simon[simonCorrectCount])
        {
          Serial.println("Right One");
          tone(buzzer, 1000);
          delay(400);
          noTone(buzzer);
          Serial.println(" Hit ");
          digitalWrite(led, HIGH);
          delay(1000);
          digitalWrite(led, LOW);
          delay(1000);
          simonCorrectCount++;
          
        }
        else if (led != Simon[simonCorrectCount])
        {
          tone(buzzer, 100);
          Serial.println("wrong3");
          delay(400);
          noTone(buzzer);
          
          gameover();
        }
        
      }
      
      else if (digitalRead(buttonPin3) == LOW)
      {

        //Serial.println("running");
        
       
        if (simonCount == 0 && simonCorrectCount == 1)
        {
           Serial.println("Passed");
           simonCount++;
           score++;
           buttonNotPressed = false;
           scoreboard();  
         }
         else if (simonCount != 0 && simonCorrectCount == simonCount+1)
         {
           Serial.println("Passed");
           simonCount++;
           score++;
           buttonNotPressed = false;
           scoreboard();
         }
         else if (simonCount != 0 && simonCorrectCount != simonCount+1)
         {
          
         }
         
        
      }


///////////////////////////////////////////////////////////////////////////////////////////

      if(digitalRead(buttonPin4) == HIGH)
      {
        led = Green;
        
        
        Serial.println("yes4");
        
        if (led == Simon[simonCorrectCount])
        {
          Serial.println("Right One");
          tone(buzzer, 1000);
          delay(400);
          noTone(buzzer);
          Serial.println(" Hit ");
          digitalWrite(led, HIGH);
          delay(1000);
          digitalWrite(led, LOW);
          delay(1000);
          simonCorrectCount++;
          
        }
        else if (led != Simon[simonCorrectCount])
        {
          tone(buzzer, 100);
          Serial.println("wrong4");
          delay(400);
          noTone(buzzer);

          gameover();
        }
        
      }
      
      else if (digitalRead(buttonPin4) == LOW)
      {

        //Serial.println("running");
        
       
        if (simonCount == 0 && simonCorrectCount == 1)
        {
           Serial.println("Passed");
           simonCount++;
           score++;
           buttonNotPressed = false;
           scoreboard();  
         }
         else if (simonCount != 0 && simonCorrectCount == simonCount+1)
         {
           Serial.println("Passed");
           simonCount++;
           score++;
           buttonNotPressed = false;
           scoreboard();
         }
         else if (simonCount != 0 && simonCorrectCount != simonCount+1)
         {
          
         }
         
        
      }

  }
  
 }

/////////////////////////////////////////////////////////////////////////////////////////////

      //if(digitalRead(buttonPin2) == HIGH )
     // {
       // led = Red;
       // buttons(); 
      //}
  
      //else if(digitalRead(buttonPin2) == LOW && LightsOn==true)
      //{
        //digitalWrite(led,LOW);
        //Serial.println(" Light Off ");
        //LightsOn=false;
        //delay(300);
      //}

///////////////////////////////////////////////////////////////////////////////////////////////

      //if(digitalRead(buttonPin3) == HIGH )
      //{
        //led=Yellow;
        //buttons();

      //}
  
      //else if(digitalRead(buttonPin3) == LOW && LightsOn==true)
      //{
        //digitalWrite(led,LOW);
        //Serial.println(" Light Off ");
        //LightsOn=false;
        //delay(300);
      //}

  
/////////////////////////////////////////////////////////////////////////////////////////////

      //if(digitalRead(buttonPin4) == HIGH )
      //{
        //led=Green;
        //buttons();
      //}
  
      //else if(digitalRead(buttonPin4) == LOW && LightsOn==true)
      //{
        //digitalWrite(led,LOW);
        //Serial.println(" Light Off ");
        //LightsOn=false;
        //delay(300);
      //}
    
    //tone(buzzer, 1000);
    //Serial.println(" Hit ");
    //digitalWrite(led, HIGH);
    //delay(300);
    //noTone(buzzer);
    //}
  /////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////

void gameover()
{
    for (int i = 0; i < simonCount+1; i++)
    {
      Serial.println(Simon[i]);
      Simon[i]=0;
    }

    lcd.setCursor(0,0);
    lcd.print("Game Over                             ");
   
    lcd.setCursor(0,2);
     lcd.print("         ");
  
    simonCorrectCount=0;
    simonCount=0;
    buttonNotPressed = true;
    score=0;
    delay(5000);
    scoreboard();

}
