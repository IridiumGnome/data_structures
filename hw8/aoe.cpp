#include <iostream>
#include <vector>

using namespace std;

vector <int> le, ee, l, e, slack;
vector <string> status;

vector <vector<int>> aoe;

void eeFunction(int event) {
	for (int i = 0; i < event; i++) {
		for (int j = 0; j < event; j++) {
			if (aoe[i][j] != 0 && ee[i] + aoe[i][j] > ee[j]) {
				ee[j] = ee[i] + aoe[i][j];
			}
		}
	}
}

void leFunction(int event) {
	int a = event - 1;
	le[a] = ee[a];
	for (int i = a; i >= 0; --i) {
		for (int j = a; j >= 0; --j) {
			if (aoe[i][j] != 0 && le[j] - aoe[i][j] < le[i]) {
				le[i] = le[j] - aoe[i][j];
			}
		}
	}
}

void elFunction(int N) {
	int k = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (aoe[i][j] != 0) {
				e[k] = ee[i];
				l[k++] = le[j] - aoe[i][j];
			}
		}
	}
}

void path(int N) {
	for (int i = 0; i < N; ++i) {
		if (e[i] == l[i]) {
            int ind = i + 1;
			cout << ind << " ";
		}
	}
}

int main()
{
    int N; // # number of activities
    cin >> N;

    aoe.resize(101);

    for(int i = 0; i < aoe.size(); i++){
        aoe[i].resize(101);
        for(int j = 0; j < 101; j++){
            aoe[i][j] = 0;
        }
    }

    int index, startV, endV, duration;

    for(int i = 0; i < N; i++)
    {
        cin >> index;
        cin >> startV;
        cin >> endV;
        cin >> duration;

        aoe[startV][endV] = duration;
    }

    int event = endV + 1;

    ee.resize(event);
    le.resize(event);

    for (int i = 0; i < event; ++i) {
		ee[i] = 0;
		le[i] = 1000;
	}

    eeFunction(event);
	leFunction(event);

	e.resize(N);
	l.resize(N);

	elFunction(N);

    cout << "\n";

    cout << "event" << "\t" << "ee" << "\t" << "le" << "\n";

    for(int i = 0; i < event; i++)
    {
        cout << i << "\t" << ee[i] << "\t" << le[i] << "\n";
    }

    cout << "\n";

    cout << "act." << "\t" << "e" << "\t" << "l" << "\t" << "slack" << "\t" << "critical" << "\n";

    int act = 1;

    for(int i = 0; i < N; i++)
    {
        cout << act << "\t" << e[i] << "\t" << l[i] << "\t";
        for(int j = 0; j < N; j++){
            int value = l[j] - e[j];
            slack.push_back(value);
            if(l[j] == e[j])
                status.push_back("YES");
            else status.push_back("NO");
        }
        cout << slack[i] << "\t" << status[i] << "\n";
        act += 1;
    }

    cout << "\n";

    path(N);

    cout << "\n";
}
