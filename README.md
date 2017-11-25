
# Server Installation

- Requirements
    - LEMP stack running
- Laravel framework
    ```
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

# Blockchain Installation

- Metamask Plugin https://github.com/MetaMask/metamask-extension/releases (https://metamask.io/#how-it-works)