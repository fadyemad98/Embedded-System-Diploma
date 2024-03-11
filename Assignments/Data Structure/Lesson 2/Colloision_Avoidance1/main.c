/*
 * CA.c
 *
 *  Created on:
 *      Author: Fady Emad
 */

/* Variables */
static int CA_Speed = 0;
static int CA_Distance = 0;
static int CA_Threshold = 50;

/* Automatic state function generated */
#define STATE_define(_stateFUN_) void ST_##_stateFUN_()
#define STATE(_stateFUN_) ST_##_stateFUN_
/* STATE pointer to function */

void (*CA_state) ();

enum {
	CA_waiting,
	CA_driving
}CA_state_id;

STATE_define(CA_waiting);
STATE_define(CA_driving);
int US_GetDistanceRandom(int l , int r , int count);


void Setup()
{
	/* init all drivers */
	/* inti IRQ */
	/* init HAL Drivers */
	/* init Block */
	/* Set State pointer for each block */
	CA_state = STATE(CA_waiting);
}
int main()
{
	Setup();

	while(1)
	{
		/* Call state for each block */
		CA_state();

	}
	return 0;
}



STATE_define(CA_waiting)
{
	/* State_Name */
	CA_state_id = CA_waiting;

	/* State_Action */
	CA_Speed = 0;
	/* DC_Motor(CA_SPeed) */

	/* Event_Check */
	/*  Call US_Get_Distance */
	CA_Distance = US_GetDistanceRandom(45, 55, 1);
	(CA_Distance <= CA_Threshold)?(CA_state = STATE(CA_waiting)):(CA_state = STATE(CA_driving));
	printf("CA_waiting State: Distance = %d  Speed = %d \n",CA_Distance , CA_Speed);
}

STATE_define(CA_driving)
{
	/* State_Name */
	CA_state_id = CA_driving;

	/* State_Action */
	CA_Speed = 30;
	/* DC_Motor(CA_SPeed) */

	/* Event_Check */
	/* Call US_Get_Distance */
	CA_Distance = US_GetDistanceRandom(45, 55, 1);
	(CA_Distance <= CA_Threshold)?(CA_state = STATE(CA_waiting)):(CA_state = STATE(CA_driving));
	printf("CA_driving State: Distance = %d  Speed = %d \n",CA_Distance , CA_Speed);

}


int US_GetDistanceRandom(int l , int r , int count)
{
	 /* this will generate random number in range l and r */
	int i;
	for(i=0; i<count; ++i){
		int rand_num = (rand() % (r - l + 1)) + l;
		return rand_num;
	}
}
