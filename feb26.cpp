#include<bits/stdc++.h>
#include<time.h>

using namespace std;

int search(double arr[], int left, int right, int tar);

int main()
{
    double s_time, e_time, ex;
    s_time = clock();
    int n, i, tar, s=0, ok;

    cin >> n ;
    double arr[n];
    for(i=0; i<n; i++)
    {
        // cin >> arr[i];
        arr[i] = rand() ;
        cout << arr[i]  << endl;
    }
    sort(arr, arr+n);
    cout << "target: ";
    cin >> tar ;
    //tar = rand() ;
    
    s = search(arr, 0, n-1, tar);
    if(s) cout << "Target number at index : " << s+1 << endl ;
    else cout << "Not found." << endl ;

    e_time = clock();
    ex = e_time - s_time ;
    cout << "time = " << ex << endl ;

}

int search(double arr[], int left, int right, int tar)
{
    if(left>right) return 0;
    int mid = (left+right)/2;
    if(arr[mid]==tar) return mid;
    else if (tar<arr[mid])
    {
        right = mid-1;
        mid = search(arr,left,right,tar);
    }
    else 
    {
        left = mid+1;
        mid = search(arr,left,right,tar);
    }   

    return mid;
}