//abdullah malik 0872 bscsD q5 pyramid code ASSIGNMENT 3
#include<iostream>
#include<cmath>
#include<string>
using namespace std;
void encrypt();
void decrypt();
void checkdatatype();
char ch,temp;// characters for decryption and temp is to store characters temporarily
unsigned int chint;
unsigned long long partA,partB,partC,partD,ch1,ch2;//ch1 ch2 is pair of characters in encryption
string message,datatodec,secretkey;
int choice,i=0,spaceat=-1,sizes,spaces=0,step=1,letters,len;// these c's are for decryption used as kind of ascii of chars that if they are -1 means no value is stored in it . chint is used in decryption indicating int value for char calculations
bool condition;
int main(){
	cout<<endl<<"enter your choice (1 to exit. 2 to encrypt. 3 to decrypt:";
	cin>>choice;
	if (choice==1){
		cout<<endl<<"exitted..";
		exit(0);
		}
	else if ( choice==2){
		cout<<"\n enter 16 digit secret key:";
		cin>>secretkey;
		cout<<endl<<"enter message  to encrypt:";
		cin>>message;
		checkdatatype();
        	// Retry if message has numbers
        	while (!condition) {
            	cin.ignore();
            	cout << endl << "Re-enter message to encrypt (without numbers): ";
            	getline(cin, message);
            	checkdatatype();
        	}
		partA= stoi(secretkey.substr(0, 4)); // will take first 4 digits
        	partB= stoi(secretkey.substr(4, 4)); //then next 4 digits
        	partC= stoi(secretkey.substr(8, 4)); // mod method gave wrong results so used more accurate one 
        	partD= stoi(secretkey.substr(12, 4)); 
		//length of message
		len=message.length();
		cout<<endl;
		encrypt();
		}
	else if (choice==3){
		cout<<endl<<"enter the data to be decrypted (<= 5 characters):";
		cin.ignore();
		getline(cin,datatodec);
		// means if secretkey is not already defined...
		len=datatodec.length();
		if (secretkey==" "){
			cout<<"\n enter 16 digit secret key:";
		cin>>secretkey;
		partA=stoi(secretkey.substr(0, 4));
        	partB=stoi(secretkey.substr(4, 4)); 
        	partC=stoi(secretkey.substr(8, 4));
        	partD=stoi(secretkey.substr(12, 4)); 
			}
		decrypt();
		}
		
	
	
	
  return 0;
}

//line 71 meaning either first char or leave one then one char ie 3rd character... len-1 indicated position of char
void encrypt(){
	i=0;
	while (i<len){
	if (i%2==0 && i==(len-1)){
		ch1=static_cast<int>(message.at(i));
		ch1=ch1 * partA;
		ch1=ch1 ^ partC;
		ch1=round(ch1 / float(partD));
		cout<<' '<<ch1;
		}
	else{
	if (i==0 || i%2==0){ 
		ch1=static_cast<int>(message.at(i));
		ch1=ch1 * partA;
		}
	else if (i%2==1){
		ch2=static_cast<int>(message.at(i));
		ch2=ch2 * partB;
		}
		
	if (i%2==1){
		// multiplied with ascii value of char got by at
		ch1=ch1 ^ partC;
		ch2=ch2 ^ partC;
		ch1=int(ch1 / float(partD));
		ch2=int(ch2 / float(partD));
		cout<<" "<<ch1<<" "<<ch2;
		}
	}
	i+=1;
	}
}

void decrypt() {
 	cout<<endl;
 	i=0;
 	step=1;  //step counter 
	spaceat= -1;
	sizes= 0;
	

    //iterate through the input data and process each encrypted number
	while (i < len) {
	temp = datatodec.at(i);
	if (temp == ' ') {
 		//extract number between spaces (this is an encrypted value)
		chint= stoi(datatodec.substr(spaceat + 1, sizes));
		spaceat= i;
            	sizes= 0;

            //reverse the encryption process:
		chint=chint * partD;       // Step 1: Multiply by partD
		chint=chint ^ partC;       // Step 2: XOR with partC (reverse of encryption)

            //divide by partA for the first character, partB for the second character
		if (step%2 == 1) {
                	chint/= partA;  // First in the pair
            	} 
            	else {
                	chint/= partB;  // Second in the pair
            	}

		chint &= 255;  // Ensure it's within the ASCII range
		ch= static_cast<char>(chint);  // Convert back to char
		cout<<ch;  //output the decrypted character
		step++;  //move to the next step 
        } 
        else {
        	sizes++;  //increment size as long as we are reading a number
        }
        i++;
        }

    //handle the last character if the message has an odd number of characters
    if (len%2 == 1 && i==(len-1)) {
    	chint= stoi(datatodec.substr(spaceat+1,sizes));  //get the last encrypted number
	chint*= partD;
	chint=chint ^ partC;
	chint&= 255;    //ensure its in the ascii range
	ch=static_cast<char>(chint);  //convert to character
	cout<<ch;  //output the final character
	}

    cout<<endl;  //newline after decryption is complete
}

void checkdatatype() {
	i=0;
    condition= true;  // assume the condition is true initially
    while (i < message.length()) {
    if (isdigit(message.at(i))) {  // check if the character is a digit
    	condition=false;  // set condition to false if a digit is found
    	break;  // exit the loop if a digit is found
        }
        i++;
    }
}

