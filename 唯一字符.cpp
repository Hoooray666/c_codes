int firstUniqChar(char * s){
    int shuzu[26]={0};
    int i;
    int j;
    int det;
    int p;
    int length = strlen(s);
    // int cnt =0;
    // shuzu[0][0]=s[0];
    // shuzu[0][1]=1;
    // for(i =0;i<26;i++){
        // shuzu[i][0]='a'+i;
        // printf("%c",shuzu[i][0]);
    // } 
        for(i=0;i<length;i++){
            // int prime =0;
            // cnt ++;
            // for(j=0;j<26;j++){
                // if(s[i]==shuzu[j][0]){
                    // shuzu[j][1]+=1;
                    // prime =1;
                    // cnt --;
                    // break;
                // }    
            // } 
            // printf("%d",shuzu[11][1]);
            // if(prime ==0){
                // shuzu[cnt][0]=s[i];
                // shuzu[cnt][1]=1;
            // } 
            int b=s[i]-'a';
            shuzu[b]++;
        }
    det =0;
    for(i =0 ;i<length;i++){
        int a = s[i]-'a';
        if(shuzu[a]==1){
            det =1;
            break;
        }
    }
    if(det ==0){
        return -1;
    }
    else{
        return i;
    }
    // for(i =0 ; i<26;i++){
            // printf("%c ",shuzu[i][0]);
    // } 
    // det =1;
    // for(p=0;p<26;p++){
        // printf("shuzu %d = %d",p,shuzu[p][1]);
        // if(shuzu[p][1]==1){
            // det =0;
            // printf("%d",p);
            // break;
        // }
    // }
    // printf("%d",shuzu[p][1]);
    // if(det ==1){
        // return -1;
    // }
    // else {
        // for(i=0;i<length;i++){
            // if(shuzu[p][0]==s[i]){
                // break;
            // }
        // }   
        // return i;
    // }  
}
