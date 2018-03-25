#include <iostream>
#include <stdlib.h>
using namespace std;
int id=0;
class Item
{
	int item_id;
	//char item_name;
	float price;
	
	
	public:

	int item_count;
	Item()
	{
		item_id=id++;
		price=10;
		item_count=2;
		
	}
	float get_price()
	{
	   return price;
	}

	void decrease_item_count()
	{

		item_count--;

	}

	void increase_item_count()
	{

		item_count++;

	}



};

class coin
{
  int count_1; // no of 1 rupee coins
  int count_5;  // no of 5 rupee coins
  int count_10; // no of 10 rupee coins
  
  public:
  coin()
  {
  	count_1=20;
  	count_5=10;
  	count_10=3;
  }
	
};

class Vending_Machine
{
	float current_balance;  // current_balance = count_1 + count_5 + count_10
	int available_items[3];
	coin* coin_obj; 

	public:

	Item* items_list[3];
	Vending_Machine()
	{
		current_balance=100; 
		for (int i=0;i<3;i++)
		{ items_list[i]= new Item();
		  available_items[i]=1; 
		   	
		}
		
		coin_obj=new coin();	
	}
	
    
    void pay_change(float num)
    {
      float sum=0;
      
      if(current_balance>=num)
      { 
	      while(sum<=num && count_10>0)
	      {
	      	sum+=10;
	      	count_10-=1;

	      }
	      while(sum<=num && count_5>0)
	      {
	      	sum+=5;
	      	count_5-=1;
	      	
	      }

	      while(sum<=num && count_1>0)
	      {
	      	sum+=1;
	      	count_1-=1;
	      	
	      }
	      
	      if(sum<num)
	      {


	      	cout <<"Not enough change!!!";

	      }
	   }  

     else
     {
     	cout <<"Not enough change!!!";
     }

    }

	void add_coins(int cnt_1,cnt_5,cnt_10)
    {
      
        count_1+=cnt_1;
      	count_5+=cnt_5;
      	count_10+=cnt_10;

     
    }
    

    void update_info(float pay,int id_of_item)
    {
    	float x=items_list[id_of_item].get_price();
    	current_balance+=x;
    	float change=pay-x;
    	items_list[id_of_item].decrease_item_count();
        pay_change(change);
    }



};



int main() {
	
	Vending_Machine VM;
	cout<< "welcome to the vending machine";
	cout<<"\nchoose any option\n" 
	    <<"\n1. find the price of an item"
	    <<"\n2. select and buy items"
	    <<"\n3. cancel request and get refund"
	    <<"\n4. exit";
	char ch;
	cin>>ch;
	int item_id;

	do 
	{
	  switch(ch)
	  {
	    case '1': cout<<"\nenter the id of the item whose price you want to know: ";
	              cin>>item_id;
	    	        cout<<"price: "<<VM.items_list[item_id]->get_price();
	    	        break; 	

	    case '2': cout<<"\n enter the id of the item you want to buy";
	              cin>>item_id;
	              if(VM.items_list[item_id]->item_count==0)
	              		cout<< "Sold Out!!!";
	              cout<<"make the payment :";
	              float p; //amount paid
	              cin>>p;
	              cout<< enter the coins added";
	              int cnt_10,cnt_1,cnt_5;
	              cin>>cnt_10>>cnt_1>>cnt_5;
	              VM.add_coins(cnt_1,cnt_5,cnt_10);
	              VM.update_info(p,item_id);

	    case '3': cout<<"\n enter the id of the item whose request you want to cancel ";
	    		      cin>>item_id;
                VM.items_list[item_id].increase_item_count;
                float p=VM.items_list[item_id]->get_price();
                VM.pay_change(p);

	    case '4': exit(0);break;
	    default: cout<< "invalid choice entered";break;


		
	  }		
		
	 cin>>ch;	
		
	} while(ch!='4');
		
	return 0;
}
