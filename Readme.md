
# simple tcp message

This project contains a simple TCP server and client for sending and receiving text messages.

## Project Structure

```
/Users/itsmhecker/Documents/voiceline
├── client
│   ├── src
│   │   └── main.rs
│   └── Cargo.toml
├── server
│   ├── src
│   │   └── main.rs
│   └── Cargo.toml
├── Cargo.toml
└── README.md
```

## Setup

1. **Install Rust**: Follow the instructions at [rust-lang.org](https://www.rust-lang.org/tools/install) to install Rust.

2. **Clone the repository**:
    ```sh
    git clone <repository-url>
    cd voiceline
    ```

## Running the Server

1. Navigate to the `server` directory:
    ```sh
    cd server
    ```

2. Run the server:
    ```sh
    cargo run
    ```

The server will start listening on `127.0.0.1:8080`.

## Running the Client

1. Open a new terminal and navigate to the `client` directory:
    ```sh
    cd client
    ```

2. Run the client:
    ```sh
    cargo run
    ```

The client will connect to the server at `127.0.0.1:8080`. You can then enter messages to send to the server, which will echo them back.

## License

This project is licensed under the MIT License.
