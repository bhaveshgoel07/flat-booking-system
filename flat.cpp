#include<iostream>
#include<string>
using namespace std;

struct flatDetails{
    int flat_number;
    string name;
    string date_start;
    
    string status;
    flatDetails *next;
};
flatDetails *head = NULL;

int flats[100] = {0};
void accept_booking(){
    flatDetails *new_flat = new flatDetails();
    
    cout<<"Enter flat number: ";
    cin>>new_flat->flat_number;
    if(flats[new_flat->flat_number]){
        cout<<"\nFlat is booked, please book another flat";
        accept_booking();
        return;
    }
    flats[new_flat->flat_number] = 1;
    cout<<"\nEnter Name of the person Booking: ";
    cin>>new_flat->name;
    cout<<"\nEnter Date of buying: (in DD-MM-YYYY): ";
    cin>>new_flat->date_start;
    
    new_flat->status = "Booked\n";
    cout<<"Flat has been booked successfully";
    new_flat->next=NULL;
    if(head){
       new_flat->next = head; 
    }
    head = new_flat;
}
void cancel_booking(){
    if(!head){
        cout<<"No flat has been booked";
        return;
    }
    int i;
    cout<<"\nEnter Flat Number";
    cin>>i;
    if(!flats[i]){
        cout<<"\nFlat is not booked, Book one now!";
        accept_booking();
        return;
    }
    flatDetails *temp = head;
    while(temp){
        if(temp->flat_number == i){
            break;
        }
        temp = temp->next;
    }
    cout<<"\nBooking for user "<<temp->name<<" and flat number"<<temp->flat_number<<" has been cancelled";
    flats[i] = 0;
    temp->status = "Cancelled";
}
void display_bookings(){
    flatDetails *temp = head;
    if(!head){
        cout<<"No flat has been booked";
        return;
    }
    while(temp){
        cout<<"\nFlat Number : "<<temp->flat_number;
        cout<<"\nName of User : "<<temp->name;
        cout<<"\nBooking Date : "<<temp->date_start;
        
        cout<<"\nStatus of Booking: "<<temp->status<<" \n";
        temp = temp->next;
    }
}

void start_booking(){
    int i;
    cout<<"\nSelect a menu option from the list\n";
    cout<<"1. Book a flat";
    cout<<"\n2. Cancel the booking";
    cout<<"\n3. Display all Bookings in our flat";
    cout<<"\n4. Status of Booking";
    cout<<"\n5. End the program\n";
    cin>>i;
    switch(i){
        case 1:
            accept_booking();
            start_booking();
            break;
        case 2:
            cancel_booking();
            start_booking();
            break;
        case 3:
            display_bookings();
            start_booking();
            break;
        case 4:
        int j;
        cout<<"Enter flat number\n";
        cin>>j;
            if(flats[j]){
                cout<<"flat is booked\n";
            }
            else cout<<"flat is not booked and can be booked\n";
            start_booking();
            break;
        case 5:
            return ;
        default:
            cout<<"Enter a valid Number between 1 and 5";
            start_booking();
            return;
    }
}

int main(){
    cout<<"==============Flat Booking System=================";
    cout<<"\n\tWelcome to Birla's Flat Booking System\n";
    cout<<"Flats are numbered from 0 to 99";
    start_booking();
    return 0;
}