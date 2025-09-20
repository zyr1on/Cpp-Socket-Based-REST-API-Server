# C++ Socket-Based REST API Server

> ⚠️ **Work in Progress** - This project is currently under active development. Features may be incomplete or subject to change.

A lightweight, high-performance REST API server built from scratch using native C++ sockets, featuring JWT authentication, custom routing, and modern C++ patterns.

## 🚧 Development Status

- ✅ **Core Socket Server** - Basic HTTP handling implemented
- ✅ **Routing System** - Function-based routing with unordered_map
- 🔄 **JWT Authentication** - Currently implementing token validation
- 🔄 **Request Parser** - HTTP parsing optimization in progress  
- ⏳ **Response Builder** - Standard HTTP responses
- ⏳ **Error Handling** - Comprehensive error management
- ⏳ **Unit Tests** - Test suite development
- ⏳ **Documentation** - API documentation

**Current Version:** `v0.1.0-alpha`

---

## Features

- ** Native Socket Programming** - Built with raw Windows Sockets API for maximum performance
- ** JWT Authentication** - Secure token-based authentication using `jwt-cpp` library
- **Fast Routing System** - Custom routing engine with `std::unordered_map` and functional programming
- **RESTful API** - Full HTTP request/response handling with proper status codes

## Tech Stack

- **Language**: C++11(mingw64)
- **Platform**: Windows (WinSock2)
- **Authentication**: JWT-CPP
- **Architecture**: Event-driven socket server
- **Parsing**: Custom HTTP parser with stream processing

## Project Structure

```
cpp-socket-api-server/
├── src/
│   ├── server.cpp        # Main server implementation & socket handling
│   └── httprouter.cpp    # Route management and request dispatching
├── include/
│   ├── httprouter.h      # Router class declarations
│   ├── httpparser.h      # HTTP request/response parsing utilities
│   ├── responses.h       # Response generation helpers
│   ├── jwt-cpp/          # JWT library headers
│   ├── openssl/          # OpenSSL cryptography headers
│   └── picojson/         # Lightweight JSON parsing library
├── lib/                  # Compiled libraries and dependencies
├── bin/                  # Built executable output directory
├── .vscode/              # Visual Studio Code workspace settings
├── .gitignore           # Git version control ignore patterns
├── CMakeLists.txt       # CMake build system configuration
└── README.md            # Project documentation and setup guide     
```


### Core Components

1. **Socket Layer** - Raw WinSock2 implementation for network communication
2. **HTTP Parser** - Custom parser that extracts method, path, headers, and body
3. **Router Engine** - Function-based routing with lambda support
4. **JWT Middleware** - Token validation and security layer
5. **Response Builder** - Standardized HTTP response generation

### Request Flow

```mermaid
graph LR
    A[Client Request] --> B[Socket Accept]
    B --> C[HTTP Parser]
    C --> D[Route Matching]
    D --> E[JWT Validation]
    E --> F[Handler Execution]
    F --> G[Response Generation]
    G --> H[Client Response]
```

## ⚙️ Configuration

### JWT Settings
```cpp
// In HttpRouter.cpp
std::string jwtSecret = "your-secret-key";    // Change this!
auto tokenExpiry = std::chrono::hours{24};    // Token lifetime
```

### Server Settings
```cpp
// In main.cpp
const int PORT = 8080;                        // Server port
const int BUFFER_SIZE = 4096;                 // Request buffer size
```


## Performance

- **Lightweight**: No heavy frameworks, minimal memory footprint
- **Fast**: Direct socket handling without abstraction layers
- **Concurrent**: Handles multiple client connections
- **Scalable**: Easy to extend with connection pooling

## Security Features

- **JWT Token Validation** - Cryptographic signature verification
- **Request Size Limits** - Buffer overflow protection
- **Input Sanitization** - Safe string handling
- **Connection Timeouts** - DoS protection

## 🙏 Acknowledgments

- [jwt-cpp](https://github.com/Thalhammer/jwt-cpp) - JWT library for C++
- Microsoft WinSock2 - Windows networking API

---

⭐ **Star this repo** if you find it helpful!
