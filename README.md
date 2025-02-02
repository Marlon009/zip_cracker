# ZipCracker v2.0

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux-lightgrey)

Ferramenta avançada para testes de penetração em arquivos ZIP protegidos por senha.

![cracker](https://github.com/user-attachments/assets/fecb8e86-a64d-4c77-8ef4-e28b002e6de5)


## 🚀 Recursos
- Ataque de dicionário com multi-threading
- Regras de mutação de senhas customizáveis
- Interface interativa com menu
- Seleção gráfica de arquivos
- Progresso em tempo real com estatísticas
- Cross-platform (Windows/Linux)

## 📦 Instalação

### Pré-requisitos
bash
# Debian/Ubuntu
sudo apt install libzip-dev g++ build-essential

# Fedora
sudo dnf install libzip-devel gcc-c++

# Arch/Manjaro
sudo pacman -S libzip gcc


Compilação: g++ -o cracker cracker.cpp -lzip -std=c++17 -pthread

# Ataque básico
./cracker backup.zip rockyou.txt

# Com mutação nível 2
./cracker -m 2 arquivo.zip lista_senhas.txt

🧩 Funcionalidades
Sistema de Mutação
Nível	Regras
1	Adiciona sufixos numéricos
2	Substituições leet (e → 3)
3	Combina maiúsculas e minúsculas
Estatísticas em Tempo Real
Copy
[+] Progresso:    1500 senhas | Tempo:    5s |    300 p/s | Descompactando... /
⚠️ Aviso Legal
Este software destina-se exclusivamente para:

Testes de penetração autorizados

Recuperação de arquivos próprios

Pesquisa em segurança digital

É estritamente proibido utilizar esta ferramenta para quaisquer atividades ilegais.

📄 Licença
Distribuído sob licença GPL-3.0. Veja o arquivo LICENSE para mais detalhes.

👨💻 Desenvolvedor
Marlon - GitHub

🙌 Contribuição
Contribuições são bem-vindas! Abra um issue ou pull request para:

Reportar bugs

Sugerir melhorias

Adicionar novas funcionalidades

Nota: Mantenha sempre autorização por escrito para qualquer teste em sistemas de terceiros.
