  #include<stdio.h>

  /* Our structure */
  struct rec
  {
     int x,y,z;
     float value;
  };

  int main()
  {
     int counter;
     struct rec my_record;
     int counter_limit;
 
     counter_limit = 100;

     for ( counter=1; counter <= counter_limit; counter++)
     {
        my_record.x = counter;
        my_record.y = counter + 1;
        my_record.z = counter + 2;
        my_record.value = (float) counter * 10.0;
        /* write out my_record */
     }
     return 0;
  }
