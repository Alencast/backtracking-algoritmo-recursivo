#include <iostream>
#include <vector>

void soma_sublista_bt(int* a, int tam, int soma, std::vector<int> sublista_atual, std::vector<std::vector<int>> todas_solucoes) {
    
    if (soma == 0) { 
        todas_solucoes.push_back(sublista_atual);
        return; 
    }
    
    if (soma < 0 || tam == 0){
        return;} 

    sublista_atual.push_back(a[tam - 1]);
    soma_sublista_bt(a, tam - 1, soma - a[tam - 1], sublista_atual, todas_solucoes);
    
    sublista_atual.pop_back();
    soma_sublista_bt(a, tam - 1, soma, sublista_atual, todas_solucoes);
}

int main() {
    int n, s;
    std::cin >> n >> s;
    
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<std::vector<int>> todas_solucoes;
    std::vector<int> sublista_atual;

    soma_sublista_bt(a, n, s, sublista_atual, todas_solucoes);

    
    if (todas_solucoes.size() > 0) {
       
        for (int i = 0; i < todas_solucoes.size(); i++) {
           
            for (int num : todas_solucoes[i]) {
                std::cout << num << " ";
            }
            std::cout << "\n";
        }
    } else {
        std::cout << "Não existe soma " << s<< " no conjunto";
    }

    delete[] a;
    return 0;
}
