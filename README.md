# 🛰️ Verificador de Conexão IP

Um pequeno programa em **C++** que verifica se há uma conexão de rede **ativa (ESTABLISHED)** com um determinado endereço **IP** no sistema.  
O programa utiliza o comando `netstat` para inspecionar as conexões abertas e informa se o IP especificado está conectado no momento.

---

## ⚙️ Funcionalidades

- Verifica conexões de rede ativas com um IP específico.  
- Exibe o comando executado no console.  
- Retorna mensagens claras sobre o status da conexão (conectado ou não).  
- Compatível com **Windows** (pode ser adaptado facilmente para Linux).

---

## 🧠 Como funciona

O programa:
1. Define o **encoding UTF-8** no console para suportar caracteres especiais.  
2. Monta um comando `netstat -an` e filtra o IP informado com `findstr`.  
3. Executa o comando usando `system()`.  
4. Analisa o **código de retorno** do comando:
   - `0` → IP encontrado com status **ESTABLISHED**.  
   - `outro valor` → IP **não encontrado** ou sem conexão ativa.

---

## 🧩 Código principal

```cpp
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(65001); // Define UTF-8 para o console
    const char* ip = ""; // IP a ser verificado

    // Monta o comando netstat
    char command[256];
    snprintf(command, sizeof(command), "netstat -an | findstr %s | findstr ESTABLISHED", ip);

    printf("Executando comando:\n %s\n", command);

    // Executa o comando
    int result = system(command);
    printf("\n");

    // Exibe o resultado
    if (result == 0) {
        printf("O IP %s está ESTABLISHED.\n", ip);
    } else {
        printf("O IP %s NÃO está ESTABLISHED.\n", ip);
    }

    return 0;
}
```

---

## 🪟 Requisitos

- **Sistema operacional:** Windows  
- **Compilador C++:** MinGW, MSVC ou similar  
- **Bibliotecas:** padrão da linguagem C (`stdio.h`, `stdlib.h`, `windows.h`)

---

## 🚀 Como compilar e executar

### 🔧 Compilação
Se estiver usando o **MinGW**:

```bash
g++ verificador_ip.cpp -o verificador_ip.exe
```

### ▶️ Execução
```bash
verificador_ip.exe
```

---

## 🧱 Personalização

Para verificar outro IP, basta alterar a linha:
```cpp
const char* ip = "165.152.227.53";
```
e substituir pelo IP desejado.

---

## 🐧 Adaptando para Linux

No Linux ou macOS, substitua:
```cpp
snprintf(command, sizeof(command), "netstat -an | findstr %s | findstr ESTABLISHED", ip);
```
por:
```cpp
snprintf(command, sizeof(command), "netstat -an | grep %s | grep ESTABLISHED", ip);
```
E remova a linha:
```cpp
#include <windows.h>
SetConsoleOutputCP(65001);
```

---

## 📜 Licença

Este projeto é de **uso livre** para fins educacionais e de monitoramento básico de rede.  
Sinta-se à vontade para modificar e distribuir.

