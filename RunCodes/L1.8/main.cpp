#include <iostream>
#include <array>
#include <string>
#define maxn 20
#define maxBallots 1000
using namespace std;
 
int main(){
    int n;
    array<string,maxn> candidates;
    array<array<int,maxn>,maxBallots> ballots;
 
    cin >> n;
 
    string lixo;
    getline(cin,lixo);
 
    for(int i=0;i<n;i++){
        getline(cin,candidates[i]);
    }
 
    int qtdVoters = 0;
    for(int i=0; cin >> ballots[i][0]; i++){
        for(int j=1;j<n;j++){
            cin >> ballots[i][j];
        }
        qtdVoters++;
    }
    array<bool,maxn> eliminated;
    while(true){
        array<int,maxn> votes;
        for(int i=0;i<n;i++)
            votes[i] = 0;
 
        for(int voter=0;voter<qtdVoters;voter++){ 
            for(int option=0;option<n;option++){
                int candidate = ballots[voter][option]-1;
                if(!eliminated[candidate]){
                    votes[candidate]++;
                    break;
                }
 
            }
 
        }
        int minVotes = qtdVoters, maxVotes = 0;
        for(int candidate=0;candidate<n;candidate++){
            if(!eliminated[candidate]){
                minVotes = min(minVotes,votes[candidate]);
                maxVotes = max(maxVotes,votes[candidate]);
            }
        }
        if(minVotes==maxVotes){
            break;
        }
        else{
            int qtdMaxVotes = 0;
            for(int candidate=0;candidate<n;candidate++){
                if(!eliminated[candidate] && votes[candidate]==maxVotes){
                    qtdMaxVotes++;
                }
            }
 
            if(qtdMaxVotes==1 && maxVotes*2>qtdVoters){
                for(int candidate=0;candidate<n;candidate++){
                    if(votes[candidate]!=maxVotes){
                        eliminated[candidate] = 1;
                    }
                }
                break;
            }
            else{
                for(int candidate=0;candidate<n;candidate++){
                    if(!eliminated[candidate] && votes[candidate]==minVotes){
 
                        eliminated[candidate] = 1;
                    }
                }
            }
        }
    }
 
    for(int candidate=0;candidate<n;candidate++){
        if(eliminated[candidate]==false){
            cout << candidates[candidate] <<"\n";
        }
    }
 
    return 0;
}