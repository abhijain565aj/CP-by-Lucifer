// // Solution by Abhi Jain aka Lucifer aka abhijain565aj
// // Mera solution kyun dekh rha?? ... (｡◕‿‿◕｡)

// // Template maine nhi banaya he pura, codeforces pe dusro k solutions se inspired template he ...
// // Kudos to them ❤

// #pragma GCC optimize("O3,unroll-loops")

// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace std;
// using namespace std::chrono;
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> // find_by_order, order_of_key

// typedef long long ll;
// typedef unsigned long long ull;
// typedef long double lld;

// #define MOD 1000000007
// #define INF 1e18

// #define vi vector<int>
// #define vb vector<bool>
// #define vs vector<string>
// #define vl vector<ll>
// #define vvi vector<vi>
// #define vvl vector<vl>
// #define pii pair<int, int>
// #define pli pair<ll, int>
// #define pll pair<ll, ll>
// #define v(x) vector<x>
// #define nextL cout << "\n"

// #define fo(i, n) for (decltype(n) i = 0; i < n; i++)
// #define re(i, n) for (decltype(n) i = n - 1; i >= 0; i--)
// #define fo1(i, a, b) for (decltype(b) i = a; i < b; i++)
// #define re1(i, a, b) for (decltype(a) i = a; i >= b; i--)

// #define YN(possible) cout << ((possible) ? "YES" : "NO") << endl;
// #define all(x) (x).begin(), (x).end()
// #define sortall(x) sort(all(x))
// #define F first
// #define S second
// #define pb push_back
// // a.resize(unique(all(a)) - a.begin());  -> unque element me convert karta hai

// #define read(a, n)              \
//     for (int i = 0; i < n; ++i) \
//         cin >> a[i];
// #define print_space(a, n)         \
//     for (int i = 0; i < n; ++i)   \
//         if (i == n - 1)           \
//             cout << a[i] << "\n"; \
//         else                      \
//             cout << a[i] << ' ';
// #ifndef ONLINE_JUDGE
// #include "./0_debug.cpp"
// #else
// #define debug(x)
// #define debug2(x, y)
// #define debug3(x, y, z)
// #define test(tt)
// #define printTC(tc)
// #endif

// // min_max functions
// template <typename T>
// T max3(T a, T b, T c)
// {
//     return max(a, max(b, c));
// }
// template <typename T>
// T max4(T a, T b, T c, T d)
// {
//     return max(max(a, d), max(b, c));
// }
// template <typename T>
// T min3(T a, T b, T c)
// {
//     return min(a, min(b, c));
// }
// template <typename T>
// T min4(T a, T b, T c, T d)
// {
//     return min(min(a, d), min(b, c));
// }

// /*
// |     /\     |  _ \  | |  | | |_   _| ( )          / ____|  / __ \  |  __ \  |  ____| |
// |    /  \    | |_) | | |__| |   | |   |/   ___    | |      | |  | | | |  | | | |__    |
// |   / /\ \   |  _ <  |  __  |   | |       / __|   | |      | |  | | | |  | | |  __|   |
// |  / ____ \  | |_) | | |  | |  _| |_      \__ \   | |____  | |__| | | |__| | | |____  |
// | /_/    \_\ |____/  |_|  |_| |_____|     |___/    \_____|  \____/  |_____/  |______| |
// */
// // class Aho_Corasick
// // {
// //     struct Node
// //     {
// //         unordered_map<char, Node *> children;
// //         Node *fail;
// //         vector<int> output;
// //     };
// //     Node *root;

// // public:
// //     vector<string> words;
// //     unordered_map<string, int> id;

// //     Aho_Corasick()
// //     {
// //         root = new Node();
// //         root->fail = root;
// //     }
// //     void insert(string &s)
// //     {
// //         id[s] = words.size();
// //         words.push_back(s);
// //         Node *cur = root;
// //         for (char c : s)
// //         {
// //             if (!cur->children.count(c))
// //                 cur->children[c] = new Node();
// //             cur = cur->children[c];
// //         }
// //         cur->output.push_back(id[s]);
// //     }
// //     void build()
// //     {
// //         queue<Node *> q;
// //         for (auto &p : root->children)
// //         {
// //             p.second->fail = root;
// //             q.push(p.second);
// //         }
// //         while (!q.empty())
// //         {
// //             Node *cur = q.front();
// //             q.pop();
// //             for (auto [ch, next_state] : cur->children)
// //             {
// //                 Node *fail = cur->fail;
// //                 while (fail != root && !fail->children.count(ch))
// //                     fail = fail->fail;
// //                 if (fail->children.count(ch))
// //                     fail = fail->children[ch];
// //                 next_state->fail = fail;
// //                 q.push(next_state);

// //             }
// //         }
// //     }
// //     set<int> search(string &s)
// //     {
// //         set<int> ans;
// //         Node *cur = root;
// //         for (char c : s)
// //         {
// //             while (cur != root && !cur->children.count(c))
// //                 cur = cur->fail;
// //             if (cur->children.count(c))
// //                 cur = cur->children[c];
// //             for (auto ids : cur->output)
// //                 ans.insert(ids);
// //         }
// //         return ans;
// //     }
// // };
// class Aho_Corasick
// {
//     struct Node
//     {
//         Node *children[26]; // Assuming lowercase English letters
//         Node *fail;
//         vector<string> output;

//         Node() : fail(nullptr)
//         {
//             fill(begin(children), end(children), nullptr);
//         }
//     };
//     Node *root;

// public:
//     Aho_Corasick()
//     {
//         root = new Node();
//         root->fail = root;
//     }
//     ~Aho_Corasick()
//     {
//         clear(root);
//     }
//     void insert(string &s)
//     {
//         Node *cur = root;
//         for (char c : s)
//         {
//             int idx = c - 'a';
//             if (!cur->children[idx])
//                 cur->children[idx] = new Node();
//             cur = cur->children[idx];
//         }
//         cur->output.push_back(s);
//     }
//     void build()
//     {
//         queue<Node *> q;
//         for (int i = 0; i < 26; i++)
//         {
//             if (root->children[i])
//             {
//                 root->children[i]->fail = root;
//                 q.push(root->children[i]);
//             }
//         }
//         while (!q.empty())
//         {
//             Node *cur = q.front();
//             q.pop();
//             for (int i = 0; i < 26; i++)
//             {
//                 if (cur->children[i])
//                 {
//                     Node *fail = cur->fail;
//                     while (fail != root && !fail->children[i])
//                         fail = fail->fail;
//                     if (fail->children[i])
//                         fail = fail->children[i];
//                     cur->children[i]->fail = fail;
//                     q.push(cur->children[i]);
//                     cur->children[i]->output.insert(cur->children[i]->output.end(), fail->output.begin(), fail->output.end());
//                 }
//             }
//         }
//     }
//     vector<string> search(string &s)
//     {
//         vector<string> ans;
//         Node *cur = root;
//         for (char c : s)
//         {
//             int idx = c - 'a';
//             while (cur != root && !cur->children[idx])
//                 cur = cur->fail;
//             if (cur->children[idx])
//                 cur = cur->children[idx];
//             for (const string &out : cur->output)
//                 ans.push_back(out); // Collect matches
//         }
//         sort(ans.begin(), ans.end());
//         ans.erase(unique(ans.begin(), ans.end()), ans.end());
//         return ans;
//     }

// private:
//     void clear(Node *node)
//     {
//         for (int i = 0; i < 26; i++)
//         {
//             if (node->children[i])
//                 clear(node->children[i]);
//         }
//         delete node;
//     }
// };

// void solve()
// {
//     Aho_Corasick ac;
//     string s;
//     cin >> s;
//     int n;
//     cin >> n;
//     vector<string> words;
//     string temp;
//     fo(i, n)
//     {
//         cin >> temp;
//         words.pb(temp);
//         ac.insert(temp);
//     }
//     ac.build();
//     auto a = ac.search(s);
//     set<string> b = set<string>(a.begin(), a.end());
//     for (auto x : words)
//         YN(b.count(x));
// }
// /*
// |   _____    ____    _____    ______     ______   _   _   _____     _____
// |  / ____|  / __ \  |  __ \  |  ____|   |  ____| | \ | | |  __ \   / ____| |
// | | |      | |  | | | |  | | | |__      | |__    |  \| | | |  | | | (___   |
// | | |      | |  | | | |  | | |  __|     |  __|   | . ` | | |  | |  \___ \  |
// | | |____  | |__| | | |__| | | |____    | |____  | |\  | | |__| |  ____) | |
// |  \_____|  \____/  |_____/  |______|   |______| |_| \_| |_____/  |_____/  |
// */
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("./0_Error.txt", "w", stderr);
// #endif
//     int testCases = 1;
//     // cin >> testCases;
//     fo(tt, testCases)
//     {
//         test(tt + 1);
// #ifndef ONLINE_JUDGE
//         // printTC(tt + 1);
// #endif
//         solve();
//     }
// #ifndef ONLINE_JUDGE
//     cerr << "------------------------------------------\n";
// #endif
// }
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

struct TrieNode
{
	unordered_map<char, TrieNode *> children;
	TrieNode *failureLink = nullptr;
	vector<int> patternIndices;
};

class AhoCorasick
{
public:
	TrieNode *root;

	AhoCorasick()
	{
		root = new TrieNode();
	}

	void insertPattern(const string &pattern, int index)
	{
		TrieNode *current = root;
		for (char c : pattern)
		{
			if (!current->children.count(c))
			{
				current->children[c] = new TrieNode();
			}
			current = current->children[c];
		}
		current->patternIndices.push_back(index);
	}

	void buildFailureLinks()
	{
		queue<TrieNode *> q;
		root->failureLink = root;

		for (auto &pair : root->children)
		{
			pair.second->failureLink = root;
			q.push(pair.second);
		}

		while (!q.empty())
		{
			TrieNode *current = q.front();
			q.pop();

			for (auto &pair : current->children)
			{
				char c = pair.first;
				TrieNode *child = pair.second;

				TrieNode *failure = current->failureLink;
				while (failure != root && !failure->children.count(c))
				{
					failure = failure->failureLink;
				}
				if (failure->children.count(c))
				{
					failure = failure->children[c];
				}
				child->failureLink = failure;

				child->patternIndices.insert(child->patternIndices.end(),
																		 failure->patternIndices.begin(),
																		 failure->patternIndices.end());

				q.push(child);
			}
		}
	}

	vector<bool> searchString(const string &text, int numPatterns)
	{
		vector<bool> foundPatterns(numPatterns, false);
		TrieNode *current = root;

		for (char c : text)
		{
			while (current != root && !current->children.count(c))
			{
				current = current->failureLink;
			}
			if (current->children.count(c))
			{
				current = current->children[c];
			}

			for (int index : current->patternIndices)
			{
				foundPatterns[index] = true;
			}
		}

		return foundPatterns;
	}

	~AhoCorasick()
	{
		deleteTrie(root);
	}

private:
	void deleteTrie(TrieNode *node)
	{
		for (auto &pair : node->children)
		{
			deleteTrie(pair.second);
		}
		delete node;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string text;
	cin >> text;

	int k;
	cin >> k;

	vector<string> patterns(k);
	AhoCorasick ac;

	for (int i = 0; i < k; ++i)
	{
		cin >> patterns[i];
		ac.insertPattern(patterns[i], i);
	}

	ac.buildFailureLinks();

	vector<bool> result = ac.searchString(text, k);

	for (bool found : result)
	{
		cout << (found ? "YES" : "NO") << '\n';
	}

	return 0;
}

