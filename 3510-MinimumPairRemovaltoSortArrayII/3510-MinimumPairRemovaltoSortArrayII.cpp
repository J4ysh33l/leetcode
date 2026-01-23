// Last updated: 23/01/2026, 22:52:42
1// this version uses long long packed data instead of pair int2
2using ll=long long;
3using int2=pair<long long, int>;
4const int N=1e5;
5bitset<N> rmv=0;
6int prv[N], nxt[N];
7ll heap[3*N];// this is changed
8class Solution {
9public:
10    // pack function 
11    static inline ll pack(ll sum, unsigned idx){
12        return ((ll)sum<<17)|idx;
13    }
14    static int minimumPairRemoval(vector<int>& nums_) {
15        const int n=nums_.size();
16        ll* nums=(ll*)alloca(n*sizeof(ll));
17        copy(nums_.begin(), nums_.end(), nums);
18
19        if (is_sorted(nums, nums+n)) return 0;
20
21        rmv.reset();
22
23        for (int i = 0; i<n; i++) {
24            prv[i]=i-1;
25            nxt[i]=(i+1<n)? i+1 : -1;
26        }
27
28        for (int i=0; i<n-1; i++)
29            heap[i]=pack(nums[i]+nums[i+1], i);
30        int sz=n-1;
31        make_heap(heap, heap+sz, greater<>());
32
33        // initial violation count
34        int bad=0;
35        for (int i=0; i<n-1; i++)
36            if (nums[i]>nums[i+1]) bad++;
37
38        int op=0;
39
40        while (bad>0 && sz>0) {
41            pop_heap(heap, heap+sz, greater<>());
42            ll data=heap[--sz];
43            // unpack data into sum & i
44            ll sum=data>>17;
45            int i=data&((1<<17)-1);
46
47            if (rmv[i] || nxt[i]==-1) continue;
48            int j=nxt[i];
49            if (rmv[j] || nums[i]+nums[j] != sum) continue;
50
51            int pi=prv[i];
52            int nj=nxt[j];
53
54            // remove old violations
55            if (pi != -1 && nums[pi]>nums[i]) bad--;
56            if (nums[i] > nums[j]) bad--;
57            if (nj != -1 && nums[j]>nums[nj]) bad--;
58
59            // merge
60            nums[i]=sum;
61            rmv[j]=1;
62
63            nxt[i]=nj;
64            if (nj != -1) prv[nj]=i;
65
66            // add new violations
67            if (pi!=-1 && nums[pi]>nums[i]) bad++;
68            if (nj!=-1 && nums[i]>nums[nj]) bad++;
69
70            // update heap using pack
71            if (pi != -1){
72                heap[sz++]=pack(nums[pi]+nums[i], pi);
73                push_heap(heap, heap+sz, greater<>());
74            }
75            if (nj != -1){
76                heap[sz++]=pack(nums[i]+nums[nj], i);
77                push_heap(heap, heap+sz, greater<>());
78            }
79            op++;
80        }
81
82        return op;
83    }
84};
85