#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

struct node{
    int intime, endtime;  //intime��Ƕ���Ԫ�س���ʱ��  endtime��¼��ĩԪ�س���ʱ�䣬�ж��Ƿ񳬹�5��
    queue<int> q;
};

int main()
{
    int n, m, k, p, index=1;
    scanf("%d%d%d%d", &n, &m, &k, &p);
    vector<int> time(k+1), result(k+1);//�˿Ͱ���ҵ������ʱ��  �˿Ͱ���ҵ�����ʱ��
    for(int i=1; i<=k; i++)
        scanf("%d", &time[i]);
    vector<node> window(n+1);   //n������n����
    vector<bool> sorry(k+1, false);
    //�ȴ�������ڵ�m����
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(index <= k){
                window[j].q.push(time[index]);
                if(window[j].endtime >= 540)  //��β���˽���ʱ�䳬�����������
                    sorry[index] = true;
                window[j].endtime += time[index];
                result[index] = window[j].endtime;
                index++;
            }
        }
    }
    //������������
    while(index <= k){
        int minIntime = window[1].intime, minWindow = 1;
        //���ҵ������п�λ�Ĵ��ڣ�Ҳ����endtime��С�Ķ���
        for(int i=2; i<=n; i++){
            if(window[i].intime < minIntime){
                minIntime = window[i].intime;
                minWindow = i;
            }
        }
        window[minWindow].q.pop(); //�ҵ����ȳ��ӵ�ʹ�����
        window[minWindow].q.push(time[index]);//���ߵ������
        window[minWindow].intime += window[minWindow].q.front(); //���׵Ľ���ʱ��仯��
        if(window[minWindow].endtime >= 540){
            sorry[index] = true;
        }
        window[minWindow].endtime += time[index]; //���¶�β�Ľ���ʱ��
        result[index] = window[minWindow].endtime;//���Լ�¼��ǰ�˿ͽ���ʱ��
        index++;
    }
    //���
    for(int i=1; i<=p; i++){
        int check;
        scanf("%d", &check);
        int temp = result[check];
        if(sorry[check] == true){
            printf("Sorry\n");
        }
        else printf("%02d:%02d\n", (temp+480)/60, (temp+480)%60);  //��ȫ���ķ���ת��Ϊ����ʱ��
    }
    return 0;
}
