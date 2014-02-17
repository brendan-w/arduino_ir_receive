#define MIN_TIME 30
#define IN_PIN 5

boolean lastState = 0;
unsigned int lastTime = 0;
unsigned int count = 0;
unsigned int countTime = 0;


void setup()
{
	Serial.begin(115200);
	pinMode(IN_PIN, INPUT);
}

void loop()
{
	boolean state = readPin();

	if(state != lastState)
	{
		changeState(state, micros() - lastTime);
		lastState = state;
		lastTime = micros();
	}

	
}

//time since last change
void changeState(boolean state, int timeSince)
{
	if((state) && (timeSince > MIN_TIME))
	{
		Serial.print(count);
                Serial.print('>');
                Serial.print(countTime);
		Serial.print('>');
		Serial.println(timeSince);
		count = 0;
                countTime = 0;
	}
	else if(!state)
	{
		count ++;
                countTime += timeSince;
	}
}

boolean readPin()
{
	return !((boolean) bitRead(PIND, IN_PIN));
}
