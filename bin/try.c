int  data[10] = {123,52,8,74,62,74,55,44,74,80};
int data_length=10;
	
void readArray(){;
	int i = 0;
	write("Please input "); 
	write(data_length);
	write(" integers to be sorted.\n");
	while (i < data_length) {
		read(data[i]); i=i+1;
	} 
}
 
void printArray() {
	int i = 0; 
	while (i < data_length) {
	//write("\n    No. "); 
	/*write(i+1);
	write(" is ");
	write(data[i]); */
	i=i+1;
       }
}

void insertSort(){
	int i = 1;
	int j;
	int temp;
	while(i < data_length){
		if(data[i] < data[i-1]){
			temp = data[i];
			j= i-1;
			//while(j>=0 && temp < data[j]){
			   //data[j+1] = data[j];
			j = j - 1;
			//}	
			//data[j+1] = temp;
		}  
		i = i + 1;  
	}     
}
/*
int BinSearch(int key){
	int low = 0;
	int high = data_length;
	int mid;
	while(low <= high){ 
		mid = (low + high) / 2;
		if(data[mid]==key) return (mid + 1);    
		if(data[mid] > key)
			high = mid -1;
		else 
			low = mid + 1;
	}
	return 0;	 
}

int main(){
	int flag;
	int i = 1;
	int position;
	int key;
	while(true){
		if (i>1 ){
			write("\nContinue? 1-yes, 0-no: ");
			read(flag);
			if (flag == 0 ) break;
			else if (flag!=1) continue;
			readArray( );
		}
		write("\nExecuting No."); write(i); 
		write(" Search:\n  The Array is:");
		printArray();
		write("\nFirst, sort array.\n");
		insertSort();
		printArray();
		write("\nThen, search keynum. Please input a key");
		read(key);
		position = BinSearch(key);
		if(position == 0)
			write("\nThe keynum is not exist in array.");
		else{
			write("\nThe keynum is No.");
			write(position);
			write("element in array.");
		}
		i = i+1;
	}	   
}*/
