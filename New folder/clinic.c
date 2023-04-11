/*
3) make it pretter
*/


#include <stdio.h>
#include <stdlib.h>
#include "stdtyp.h"

#define password 1234
#define no_slots 5 /*make sure to edit the code if you change this*/
#define name_length 30
#define exit 9
#define admin_menu() do{ \
						printf("admin mode:\n");\
						printf("please enter 1 to add a new patient record.\n");\
						printf("please enter 2 to edit patient record.\n");\
						printf("please enter 3 to reserve a slot with the doctor.\n");\
						printf("please enter 4 to cancel reservation.\n");\
						printf("or please enter 9 to exit admin mode.\n");\
						}while(0)
							
#define user_menu() do{ \
						printf("user mode:\n");\
						printf("please enter 1 to view patient record.\n");\
						printf("please enter 2 to view today reservations.\n");\
						printf("or please enter 9 to exit admin mode.\n");\
						}while(0)

typedef struct patient
{
	u8 Gender;
	s8 Age;
	u8 Name[name_length];
	u16 ID;
}patient;

typedef struct reservation 
{
	u8 taken_flag;
	u16 ID;
}reserv;

typedef struct node
{  
	struct patient* data; 
	struct node* nxt;
	struct node* prev;
}node;

enum modes{admin=1,user};
enum admin_menu{new=1,edit,res_slt,cancle_slt};
enum user_menu{view_pat=1,view_slt};

node* new_patient(node* last,u16 id);/* catch the return ptr with the last_node */
patient* find_patient(node* last,u16 id); /*  returns 0 if not found and adress if found,you must have at lease 1 patient otherwise the program will crash*/
void edit_patient(patient* x);
void reserv_slot(reserv* slots,node* last_node);
void cancle_slot(reserv* slots);
void view_res(reserv* x);
void view_patient(patient* x);
u8 check_password(void);

int main(void)
{
	
	u8 mode,i,choice,flag,name[name_length],resv_counter,flag2;
	u32 pass;
	s32 id; /*signed to check for negative input*/
	u16 patient_counter;/*to make sure " find_patient" isn't used when there is 0 patients*/
	reserv slots[no_slots];
	node* last_node=(node*)0;
	patient* patient_ptr;
	patient_counter=0;
	resv_counter=0;
	/* initialize the slots array , non of them are taken*/
	for(i=0;i<5;i++)
	{
		slots[i].taken_flag=0;
		slots[i].ID=0;
	}
	
	while(1)/* main program loop , keeps on till terminated by the user*/ 
	{
		while(1)/* a validation loop to make sure the user didn't enter something wrong*/
		{
			printf("please enter 1 for admin mode\n");
			printf("please enter 2 for user mode\n");
			printf("please enter 9 to exit program\n");
			fflush(stdin);
			scanf("%i",&mode); /*scaning for the mode*/
			if(mode == admin || mode == user || exit==mode)/* if the input is right , break the validation loop*/
			{
				break;
			}
			else
			{
				printf("incorrect input\n");	
			}
		}
		
		if(admin == mode)
		{
			if( check_password() )/* only enter when the function returns true , i.e. when the user enter the right password , else shut down*/
			{
				flag=1;;/*flag that controls the admin menu, this flag is cleared when the user wants to exist admin mode*/
				while(flag)
				{
					while(1)
					{/* a validation loop to make sure the user didn't enter something wrong*/
						admin_menu();
						fflush(stdin);
						flag2=scanf("%i",&choice);
						if(flag2 )/* if the input is right , break the validation loop*/
						{
							break;
						}
						else
						{
							printf("incorrect input\n");
						}
					}
					switch (choice)
						{
							case new:/*adding new patient*/
							{
								
								while(1)/* a validation loop to make sure the id entered does not already exist*/
								{
									while(1)
									{/* a validation loop to make sure the user didn't enter something wrong*/
										printf("please enter the patient ID:");
										fflush(stdin);
										flag2=scanf("%i",&id);
										if(flag2 && id >=0)/* if the input is right(making sure the ID is a +ve number) , break the validation loop*/
										{
											break;
										}
										else
										{
											printf("incorrect input\n");
										}
									}
									
									/* in case there is 0 patients, there is no need to check if the ID already exist*/
									if(!patient_counter)/* making sure that there is no patient*/
									{
										last_node=new_patient(last_node,id);
										patient_counter++;
										break;
									}
									else
									{
										patient_ptr=find_patient(last_node,id);/* returns 0 if not found and adress if found*/
										if(!patient_ptr)/* if not found*/
										{
											last_node=new_patient(last_node,id);
											patient_counter++;
											break;
										}
										else 
										{
											printf("the ID already exist\n");
										}
									}
									
								}
								break;
								
								
							}
							
							case edit:/* editing an existing patient*/
							{
								if(!patient_counter)/*if there is 0 patients, we can't edit*/
								{
									printf("there is no registered patients\n");
									break;
								}
								
								do
								{/*a validation loop to make sure the ID exist*/
									while(1)
									{/* a validation loop to make sure the user didn't enter something wrong*/
										printf("please enter the patient ID : ");
										fflush(stdin);
										flag2=scanf("%i",&id);
										if(flag2 && id >=0)/* if the input is right(making sure the ID is a +ve number) , break the validation loop*/
										{
											break;
										}
										else
										{
											printf("incorrect input\n");
										}
									}
									patient_ptr=find_patient(last_node,id);/* checking if the ID already exist*/
									if(!patient_ptr)/*if ID does not already exist, either get another ID or exit*/
									{
										while(1)
										{/* validation loop*/
											printf("ID not found, enter 1 to try again or enter 0 to return to admin menu\n");
											fflush(stdin);
											scanf("%i",&flag2);/* if flag2=1 repeat the do-while loop*/ 
											if(1==flag2 || 0==flag2)
											{
												break;
											}
											else
											{
												printf("incorrect input\n");
											}										
										}
										
									}
									else/*if the Id is found , edit and break the do-while loop*/
									{
										edit_patient(patient_ptr);
										flag2=0;
									}
								}while(flag2);
								break;
							}
							
							case res_slt:/* reserving a time slot*/	
							{
								if(no_slots == resv_counter)/*everything is reserved*/
								{
									printf("there is no empty slots\n");
									break;
								}
								else if(0==patient_counter) /* we can't reserve a slot without having any patients*/
								{
									printf("there is no registered patients\n");
									break;
								}
								reserv_slot(slots,last_node);
								resv_counter++;
								break;
							}			
							
							case cancle_slt:/*cancling a time slot*/
							{
								if(!resv_counter)/* if nothing is reserved*/
								{
									printf("there is no reserved slots\n");
									break;
								}
								cancle_slot(slots);
								break;
							}
							
							case exist:
							{
								flag=0;/* the flag that controls the admin menu loop*/
								break;
							}
							
							default:
							{
								printf("incorrect input\n");
							}
						}
				}
			}
			else
			{/*in case of in correct password*/
				printf("you have been locked out of the system\n");	
				printf("shuting down...\n");
				return 0;
			}
		}		
		else if(user == mode)
		{
			flag=1;/*flag that controls the user menu, this flag is cleared when the user wants to exist user mode*/
			while(flag)
			{/*user menu-loop*/
				while(1)
				{/* a validation loop to make sure the user didn't enter something wrong*/
					user_menu();
					fflush(stdin);
					flag2=scanf("%i",&choice);
					if(flag2 )
					{
						break;
					}
					else
					{
						printf("incorrect input\n");
					}
				}
				switch(choice)
				{
					case view_pat:
					{
						if(!patient_counter)/* there must be a registered patient to view*/
								{
									printf("there is no registered patients\n");
									break;
								}
						
						do
						{
							while(1)
							{/* a validation loop to make sure the user enter a right ID*/
								printf("please enter the patient ID:");
								fflush(stdin);
								flag2=scanf("%i",&id);
								if(flag2 && id >=0)
								{
									break;
								}
								else
								{
									printf("incorrect input\n");
								}
							}
							patient_ptr=find_patient(last_node,id);
							if(!patient_ptr)
							{
								while(1)
								{/* validation loop*/
									printf("ID not found, enter 1 to try again or enter 0 to return to user menu\n");
									fflush(stdin);
									scanf("%i",&flag2);/* if flag2=1 repeat the do-while loop*/ 
									if(1==flag2 || 0==flag2)
									{
										break;
									}
									else
									{
										printf("incorrect input\n");
									}										
								}
							}
							else
							{
								view_patient(patient_ptr);
								while(1)
								{/* validation loop*/
									printf("enter 1 to try again or enter 0 to return to user menu\n");
									fflush(stdin);
									scanf("%i",&flag2);/* if flag2=1 repeat the do-while loop*/ 
									if(1==flag2 || 0==flag2)
									{
										break;
									}
									else
									{
										printf("incorrect input\n");
									}										
								}
							}
						}while(flag2);
						
						break;
					}
					case view_res:
					{
						if(!resv_counter)
								{
									printf("there is no reserved slots\n");
									break;
								}
						view_res(slots);
						break;
						
					}
					case exit:
					{
						flag=0;/* exiting user mode*/
						break;

					}
					default:
					{
						printf("incorrect input\n");
					}
				}
			}
		}
		else if(exit==mode)
			{
				printf("shutting down...../n");
				return 0;
			}
		else 
			{
				printf("incorrect input\n");
			}
		}
}


node* new_patient(node* last,u16 id) /* catch the return ptr with the last node.nxt then assign last=last.nxt*/
{
	u8 gender,flag;
	s8 age;
	u8 name[name_length];
	if(!last)
	{
		last=(node*) malloc(sizeof(node));
		last->nxt=(node*) 0;
		last->prev=(node*) 0;
		
	}
	else
	{
		last->nxt=(node*) malloc(sizeof(node));
		last->nxt->prev=last;
		last->nxt->nxt=(node*) 0;
		last=last->nxt;
	}
	last->data=(patient*) malloc(sizeof(patient));	
	last->data->ID=id;
	while(1)
	{
		printf("please enter new patient age:");
		fflush(stdin);
		flag=scanf("%i",&age);
		if(flag && age>=0 && age<127)
		{
			break;
		}
		else
		{
			printf("incorrect input\n");
		}
	}
	last->data->Age=age;
	while(1)
	{
		printf("please enter new patient gender (M for male and F for female): ");
		fflush(stdin);
		flag=scanf("%c",&gender);
		if(flag && ('m'==gender ||'M'==gender ||'f'==gender ||'F'==gender ) )
		{
			if('m'==gender)
			{
				gender='M';
			}
			else if('f'==gender)
			{
				gender='F';
			}
			break;
		}
		else
		{
			printf("incorrect input\n");
		}
	}
	last->data->Gender=gender;
	printf("please enter the patient name: ");
	fflush(stdin);
	scanf("%s",&(last->data->Name));
	return last;
	}

patient* find_patient(node* last_node,u16 id) /* pass the last node ptr and the id for required patient, function returns 0 address if not found, thus must be checked before using */
{
	while(last_node->data->ID != id)
	{
		if (last_node->prev !=0)
		{
			last_node=last_node->prev;
		}
		else 
		{
			return (patient*)0;
		}
	}
	return last_node->data;
	
}

void edit_patient(patient* x) //pass pointer to patient directly
{
	
	u8 gender,choice,flag;
	s8 age;
	u8 name[name_length];
	u32 id; /*unsigned to check for -ve numbers*/
	while(1)
	{
		while(1)
		{
			printf("please select a parameter to edit:\n");
			printf("enter 1 to edit ID\n");
			printf("enter 2 to edit Age\n");
			printf("enter 3 to edit Gender\n");
			printf("enter 4 to edit Name\n");
			printf("enter 9 to exit\n");
			fflush(stdin);
			flag=scanf("%i",&choice);
			if(flag)
			{
				break;
			}
			else
			{
				printf("incorrect input\n");
			}
		}
		
		switch (choice)
		{
			case 1:
			{
				while(1)
				{
					printf("please enter new patient ID:");
					fflush(stdin);
					flag=scanf("%i",&id);
					if(flag && id>=0)
					{
						break;
					}
					else
					{
						printf("incorrect input\n");
					}
				}
				
				x->ID=id;
				break;
			}
			
			case 2:
			{
				while(1)
				{
					printf("please enter new patient age:");
					fflush(stdin);
					flag=scanf("%i",&age);
					if(flag && age>=0 && age<127)
					{
						break;
					}
					else
					{
						printf("incorrect input\n");
					}
				}
				
				x->Age=age;
				break;
			}
			
			case 3:	
			{
				while(1)
				{
					printf("please enter new patient gender (M for male and F for female): ");
					fflush(stdin);
					flag=scanf("%c",&gender);
					if(flag && ('m'==gender ||'M'==gender ||'f'==gender ||'F'==gender ) )
					{
						if('m'==gender)
						{
							gender='M';
						}
						else if('f'==gender)
						{
							gender='F';
						}
						break;
					}
					else
					{
						printf("incorrect input\n");
					}
				}
				
				x->Gender=gender;
				break;
			}			
			
			case 4:
			{
				printf("please enter new patient name: "); 
				fflush(stdin);
				scanf("%s",&(x->Name));
				break;
			}
			
			case 9:
			{
				return;
			}
			
			default:
			{
				printf("incorrect input\n");
			}
			
			
		}
		
		
	}
	
}

void reserv_slot(reserv* slots,node* last_node)/* need to make sure its not out of choices using J and 0 to check if its in the range*/
{
	
	u8 i;
	u8 choice;
	u8 j;
	u8 flag;
	u32 id;
	while(1)
	{
		
		while(1)
		{
			flag=1;
			j=0;
			for(i=0;i<5;i++)
			{
				
				if(!slots[i].taken_flag)
				{
					if(flag)
					{
						printf("please select a time slot to delete:\n");
					}
					flag =0;
					switch (i)
					{
						case 0: 
							{
								printf("enter %i to reserve 2:00 pm to 2:30 pm\n",++j);
								break;
							}
						case 1: 
							{
								printf("enter %i to reserve 2:30 pm to 3:00 pm\n",++j);
								
								break;
							}
						case 2: 
							{
								printf("enter %i to reserve 3:00 pm to 3:30 pm\n",++j);
								
								break;
							}
						case 3: 
							{
								printf("enter %i to reserve 4:00 pm to 4:30 pm\n",++j);
								
								break;
							}
						case 4: 
							{
								printf("enter %i to reserve 4:30 pm to 5:00 pm\n",++j);
								break;
							}
					}
					
				}
			}
			if(flag)
			{
				printf("there is no available slots to reserve\n");
				return;
			}
			printf("or enter 9 to exit\n");
			fflush(stdin);
			flag=scanf("%hi",&choice);
			
			if(flag && ( (choice>0 && choice<=j) ||( 9==choice)))
			{
				break;
			}
			else
			{
				printf("incorrect input\n");
			}
		}
		
		if(9== choice )
		{
			return;
		}
		for(i=0;choice>0;i++)
		{
			if(!slots[i].taken_flag)
			{
			choice--;
			}
			if(!choice)
			{
				
				slots[i].taken_flag=1;
				while(1)
				{
					printf("please enter patient id:");
					fflush(stdin);
					scanf("%i",&id);
					
					
					if(id<0)
					{	
						printf("incorrect input\n");
					}
					else if(!find_patient(last_node,id))
					{
						printf("this ID does not exist\n");
					}
					else
					{
						slots[i].ID=id;
						break;
					}
					
											
				}
				
				
			}
		}
		
	}
}

void cancle_slot(reserv* slots)/* need to make sure its not out of choices using J and 0 to check if its in the range*/
{
	
	u8 choice,i,j;
	u8 flag;
	while(1)
	{
		while(1)
		{
			flag=1;
			
			for(i=0,j=0;i<5;i++)
			{
				if(slots[i].taken_flag)
				{
					if(flag)
					{
						printf("please select a time slot to delete:\n");
					}
					flag=0;
					switch (i)
					{
						case 0: 
							{
								printf("enter %i to cancle 2:00 pm to 2:30\n",++j);
								
								break;
							}
						case 1: 
							{
								printf("enter %i to cancle 2:30 pm to 3:00 pm\n",++j);
								
								break;
							}
						case 2: 
							{
								printf("enter %i to cancle 3:00 pm to 3:30 pm\n",++j);
								
								break;
							}
						case 3: 
							{
								printf("enter %i to cancle 4:00 pm to 4:30 pm\n",++j);
								
								break;
							}
						case 4: 
							{
								printf("enter %i to cancle 4:30 pm to 5:00 pm\n",++j);
								
								break;
							}
							
					}
					
				}
				
			}
			if(flag)
			{
				printf("there is no available slots to reserve\n");
				return;
			}
			printf("or enter 9 to exit\n",j);
			fflush(stdin);
			flag=scanf("%hi",&choice);
			/* need to make sure its not out of choices using J and 0 to check if its in the range*/
			if(flag && ( (choice>0 &&choice<=j) || 9==choice))
			{
					break;
			}
			else
			{
					printf("incorrect input\n");
			}
		}
	

		if( 9 == choice)
		{
			return;
		}
		for(i=0;choice>0;i++)
		{
			if(slots[i].taken_flag)
			{
			choice--;
			}
			if(!choice)
			{
				slots[i].taken_flag=0;
			}
		}
		
	}
}

void view_res(reserv* slots)
{
	u8 i;
	for(i=0;i<5;i++)
	{
		if(slots[i].taken_flag)
		{
			switch (i)
			{
				case 0: 
						{
							printf("2:00 pm to 2:30 pm is taken by ID: %i\n",slots[i].ID);
							break;
						}
				case 1: 
						{
							printf("2:30 pm to 3:00 pm is taken by ID: %i\n",slots[i].ID);
							break;
						}
				case 2: 
						{
							printf("3:00 pm to 3:30 pm is taken by ID: %i\n",slots[i].ID);
							break;
						}
				case 3: 
						{
							printf("4:00 pm to 4:30 pm is taken by ID: %i\n",slots[i].ID);
							break;
						}
				case 4: 
						{
							printf("4:30 pm to 5:00 pm is taken by ID: %i\n",slots[i].ID);
							break;
						}
			}
		}
		
	}
		
}

void view_patient(patient* x)
{
	printf("patient name:%s\n",x->Name);
	printf("patient ID:%i\n",x->ID);
	printf("patient Gender:%c\n",x->Gender);
	printf("patient Age: %i\n",x->Age);
	
}

u8 check_password(void)
{
	u8 i;
	u32 pass;
	for(i=0;i<3;i++)
			{
				printf("please enter the admin password");
				fflush(stdin);
				scanf("%i",&pass);/* scaning for the password*/
				if(password == pass)
				{
					return 1;
				}
				else 
				{
					printf("incorrect password\n");
				}
			}
	return 0;
}