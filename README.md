# Sistema de gestão de stands e venda de veículos

Este trabalho da unidade curricular de Programação Orientada a Objetos (POO) foca o
desenvolvimento de uma aplicação na linguagem de programação C++, seguindo as boas práticas que o paradigma POO sugere.

## Tema do Trabalho

Desenvolvimento de um sistema de gestão de stands de venda de veículos. Serão disponibilizados os
detalhes para cada fase de entrega do trabalho.
O trabalho será desenvolvido em três fases.

**Fase 1:** Modelação e implementação das classes que permitam representar a lógica de funcionamento da aplicação.

**Fase 2:** Completar a solução com classes para facilitar a sua manutenção.

**Fase 3:** Criação de uma interface gráfica em QT.

### Estrutura do Projeto

- **`/src`:** Contém o código-fonte da aplicação.
- **`/docs`:** Documentação do projeto.
- **`/images`:** Imagens do projeto

### Como Iniciar

#### Pré-requisitos

Certifique-se de ter instalado:

1. **Compilador C++:**
   - Recomendado: GCC, [Visual Studio](https://visualstudio.microsoft.com/), ou outro de sua escolha.
2. **Gerenciador de Versões (opcional):**
   - Recomendado: [Git](https://git-scm.com/).

#### Instalação

1. Clone o repositório:

   ```bash
   git clone https://github.com/EECPOO2324/tp-01.git
   ```

2. Navegue até o diretório do projeto:

   ```bash
   cd tp-01/src
   ```

3. Compile o código-fonte:

   ```bash
   g++ -o main main.cpp
   ```

4. Execute o aplicativo:

   ```bash
   ./main
   ```

# Utilização Inicial

Para utilizar o sistema de gestão de stands e venda de veículos, o arquivo "users_data.txt" já contém 3 utilizadores com as respetivas funções (administrador, gestor e cliente). Isso facilitará o teste do sistema pelo professor. Aqui estão os detalhes:

## Administrador:

- **Username:** admin
- **Password:** admin

## Gestor:

- **Username:** gestor
- **Password:** gestor

## Cliente:

- **Username:** cliente
- **Password:** cliente

## Stands e Veículos:
Deixamos por defeito o ficheiro "stands_data.txt" para o programa iniciar sem dar erro ao abrir o ficheiro. Dependendo do IDE, poderá não estar a abrir bem o ficheiro, pois depende muito de qual é o diretório a qual o IDE irá buscar os ficheiros, portanto aconselhamos a criar um stand individualmente e então posteriormente será criado o respetivo ficheiro no diretório default do seu IDE.
Para testar a leitura dos dados CSV deixamos também o ficherio "stands.csv" e também segue a mesma lógica do anterior, tera de verificar qual o diretório default que o seu IDE abre os ficheiros de leitura.

## Funcionalidades Principais

### 1. Autenticação de Utilizador

- **Menu Inicial:** Apresenta opções para autenticação de utilizadores.
- **Login:** Permite que utilizadores acedam ao sistema com as suas credenciais.

### 2. Administração

- **Gestão de Administradores:** Permite a criação, edição, listagem e remoção de administradores.
- **Gestão de Gestores:** Permite a criação, edição, listagem e remoção de gestores.

### 3. Gestão de Clientes

- **Criação de Clientes:** Permite a criação de novos clientes.
- **Edição de Clientes:** Permite a edição de dados de clientes existentes.
- **Listagem de Clientes:** Apresenta uma lista de clientes registados.
- **Remoção de Clientes:** Permite a remoção de clientes do sistema.

### 4. Gestão de Stands e Veículos

- **Criação de Stands:** Permite a criação de novos stands.
- **Criação de Veículos:** Permite a adição de novos veículos a um stand.
- **Movimentação de Veículos:** Facilita a transferência de veículos entre stands.
- **Remoção de Veículos:** Permite a remoção de veículos de um stand.
- **Edição de Dados de Veículos:** Permite a edição de informações de veículos existentes.

### 5. Menu do Cliente

- **Edição de Dados Pessoais:** Permite que o cliente edite os seus próprios dados.
- **Listagem de Veículos num Stand:** Apresenta a lista de veículos disponíveis num stand.
- **Listagem de Stands por Cidade:** Exibe a lista de stands por cidade.
- **Compra de Veículos:** Inicia o processo de compra de um veículo.
- **Histórico de Compras do Cliente:** Mostra o histórico de compras do cliente.
- **Alteração de Saldo do Cliente:** Permite a alteração do saldo do cliente.
