#include <iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = -987654321;
    int row=board.size();
    int col=board[0].size();
    if(row==1 || col==1){
        for(int i=0 ;i<row; i++){
            for(int j=0; j<col ; j++){
                if(board[i][j]) return 1;
            }
        }
        return 0;
    }
    else{
        for(int i=1; i<row; i++){
            for(int j=1; j<col; j++){
                if(board[i][j]){
                    board[i][j]=min(min(board[i-1][j-1],board[i-1][j]),board[i][j-1])+1;
                }
                answer=max(answer,board[i][j]);
            }
        }
    }

    return pow(answer,2);
}
//https://coding-insider.tistory.com/entry/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-2-%EA%B0%80%EC%9E%A5-%ED%81%B0-%EC%A0%95%EC%82%AC%EA%B0%81%ED%98%95-%EC%B0%BE%EA%B8%B0-CC-%E2%98%85%E2%98%85%E2%98%85?category=869841
//참고
//출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges