    /////////////// Stress testing /////////////////
   while(true) {
//        ll n = 2601;
       ll n = rand()%10+1;
       if(fast(n) == slow(n)) cout << n << " OK!\n";
       else {
           cout << "NOT MATCHED!\n";
           cout << n << endl << slow(n) << " " << fast(n);
           break;
       }
   }
