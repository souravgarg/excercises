#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class UniqueUrls {
	public:
	void print_unique_urls(const string &hashtag, ifstream &tweets_stream) {
		if (!tweets_stream.is_open())
			return;
		string tweet;
		map<string, int> tweets_map;
		// Reading first 100 tweets from tweets_stream.
		for (int i = 0; i < 100; i++) {
			getline(tweets_stream, tweet);
			int index = tweet.find(hashtag);
			// Check if hashtag exist in tweet. 
			if (index < tweet.size())
				tweets_map[tweet]++;
		}
		
		if (tweets_map.size() == 0) {
			cout << "No URL found with hashtag: " << hashtag << endl;
			return;
		} else {
			cout << endl << "***** Following Unique Urls match with hashtag: "
				<< hashtag << " ****" << endl << endl ;
		}
		map<string, int>::iterator iter;
		for (iter = tweets_map.begin(); iter != tweets_map.end(); iter++) {
			cout << iter->first << endl << endl;
		}

	}
};

int main() {
	string hashtag, tweets_filename;
	cout << "Enter hashtag without # prefixed (i.e. Enter 'sourav')" << endl;
	cin >> hashtag;
	cout << "Enter file path containing tweets (i.e. Enter 'tweet_stream_txt')"
		<< endl;
	cin >> tweets_filename;

	ifstream tweets_stream;
	tweets_stream.open(tweets_filename.c_str());
	while (!tweets_stream.is_open()) {
		cout << "Please enter correct file name" << endl;
		cin >> tweets_filename;
		tweets_stream.open(tweets_filename.c_str());
	}
	UniqueUrls *test_object = new UniqueUrls();
	test_object->print_unique_urls(hashtag, tweets_stream);
	return 0;
}
