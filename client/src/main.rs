use std::net::TcpStream;
use std::io::{self, Write, Read};

fn main() {
    let mut stream = TcpStream::connect("127.0.0.1:8080").unwrap();
    println!("Connected to server at 127.0.0.1:8080");

    loop {
        let mut input = String::new();
        println!("Enter message to send: ");
        io::stdin().read_line(&mut input).unwrap();
        stream.write_all(input.as_bytes()).unwrap();

        let mut buffer = [0; 1024];
        match stream.read(&mut buffer) {
            Ok(n) => {
                println!("Received echo: {}", String::from_utf8_lossy(&buffer[..n]));
            }
            Err(e) => {
                println!("Failed to receive data: {}", e);
                break;
            }
        }
    }
}
