using namespace std;

int main(void){
    int broj_opazanja;
    scanf("%d", &broj_opazanja);

    vector<vector<int>> data = {};

    int t1 = 0;
    int t2 = 0;

    for (int i = 0; i < broj_opazanja; ++i) {
        int vrijeme, djete, pogodzeno;
        scanf("%d%d%d", &vrijeme, &djete, &pogodzeno);
        data.push_back({vrijeme, djete, pogodzeno});
    }

    for (int i = 0; i < data.size(); ++i) {
        int djete = data[i][1];
        if (djete < 5){
            t1 += 100;
        }
        else{
            t2 += 100;
        }
    }

    for (int i = 0; i < data.size(); ++i) {
        if (i == 0){
            continue;
        }
        int vrijeme = data[i][0];
        int djete = data[i][1];

        for (int j = 0; j < i; ++j) {
            if (djete != data[j][1]){
                continue;
            }
            if (data[j][0] + 10 >= vrijeme){
                if (djete < 5){
                    t1 += 50;
                }
                else{
                    t2 += 50;
                }
            }
        }
    }

    cout << t1 << " " << t2;
    return 0;

}