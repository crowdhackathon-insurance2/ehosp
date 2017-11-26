
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
```
cd blockchain
yarn install
```

- Metamask Plugin https://github.com/MetaMask/metamask-extension/releases (https://metamask.io/#how-it-works)