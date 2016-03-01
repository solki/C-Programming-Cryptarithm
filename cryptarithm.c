//
//  main.c
//  Ass1
//  "cross + roads = danger"
//  Created by Xi Zhang on 1/03/2016.
//  Copyright © 2016 Xi Zhang. All rights reserved.
//

#include <stdbool.h>
#include <stdio.h>

bool is_cross_valid(int);
bool is_roads_valid(int);
bool is_duplicated(int);


int main(void) {
    // insert code here...
    
    for(int i = 1234; i <= 9876; ++i) {
        
        if(is_duplicated(i))
            continue;
        
        for(int j = 98765; j >= 12345; --j) {
            
            int cross = i * 10 + (i % 10);
            
            if((cross + j) < 100000)
                break;
            
            if((i%10) != (j%10))
                continue;
            
            
            if(((i/10)%10) != ((j/1000)%10))
                continue;
            
            if(((i/100)%10) != ((j/10000)%10) || ((i/100)%10) != ((cross+j)%10))
                continue;
            
            if(((j/10)%10) != (((cross+j)/100000)%10))
                continue;
            
            if(((j/100)%10) != (((cross+j)/10000)%10))
                continue;
            
            if(is_duplicated(j))
                continue;
            
            if(is_duplicated(cross + j))
                continue;
            
            if(is_duplicated((i*100+((j/10)%100))*1000+(((cross+j)/10)%1000)))
                continue;
            
            printf("cross = %d, roads = %d and danger = %d is a solution.\n", cross, j, cross+j);
            
        }
    }
    return 0;
}


bool is_duplicated(int num) {
    
    int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    while(num) {
        if(arr[num % 10])
            return true;
        else {
            arr[num % 10] = 1;
            num /= 10;
        }
    }
    
    return false;
}
