nclude <iostream>
using namespace std;

char id[] = {'W','T','L'};

double getInput(char& res){
        float a,t;
            res = 'W';
                scanf("%f",&a);
                    scanf("%f",&t);
                        if(t > a){
                                    a = t;
                                            res = 'T';
                                                }
                            scanf("%f",&t);
                                if(t>a){
                                            a = t;
                                                    res = 'L';
                                                        }
                                    return a;
}
int main() {

        float a,b,c;
            char aa='W',bb='W',cc='W';
                a = getInput(aa);
                    b = getInput(bb);
                        c = getInput(cc);
                            printf("%c %c %c %.2f\n",aa,bb,cc,(a*b*c*0.65F-1)*2.0F+0.005F);
                                return 0;
}

}
                                }
                        }
}
