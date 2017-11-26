
# Server Installation

- Requirements
    - LEMP stack running
- Laravel framework
    ```
    cd server
    composer install
    yarn install
    cp .env.example .env
    php artisan key:generate
    ```
    create the database table and add your database credentials to .env file
    ```
    php artisan migrate
    ```
    to run the server locally, in development mode:
    ```
    php artisan serve
    ```

# Arduino Installation
 - Open the connetions.png for arduino wire connections
 - Install mfrc522 library in arduino IDE 
# Blockchain Installation

- Requirements
    - NodeJS v8.4.0
    - Yarn 0.27.5

- Installation
    ```
    cd blockchain
    yarn install
    ```
- Running
    - Start Ethereum test RPC
    ```
    node_modules/.bin/testrpc
    ```
    - In a new terminal compile and run contracts
    ```
    node_modules/.bin/truffle compile
    node_modules/.bin/truffle migrate
    ```
    - Run truffle console and in there interact with contracts

- Metamask Plugin https://github.com/MetaMask/metamask-extension/releases (https://metamask.io/#how-it-works)