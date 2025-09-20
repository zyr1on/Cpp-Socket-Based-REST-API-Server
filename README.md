# C++ Socket-Based REST API Server

A lightweight, high-performance REST API server built from scratch using native C++ sockets, featuring JWT authentication, custom routing, and modern C++ patterns.

## ✨ Features

- **🚀 Native Socket Programming** - Built with raw Windows Sockets API for maximum performance
- **🔐 JWT Authentication** - Secure token-based authentication using `jwt-cpp` library
- **⚡ Fast Routing System** - Custom routing engine with `std::unordered_map` and functional programming
- **📡 RESTful API** - Full HTTP request/response handling with proper status codes
- **🎯 Zero Dependencies** - Minimal external dependencies, uses standard C++17
- **🛡️ Type Safety** - Leverages modern C++ features for safe, maintainable code

## 🛠️ Tech Stack

- **Language**: C++17
- **Platform**: Windows (WinSock2)
- **Authentication**: JWT-CPP
- **Architecture**: Event-driven socket server
- **Parsing**: Custom HTTP parser with stream processing

## 📦 Project Structure

```
├── main.cpp              # Server entry point & socket initialization
├── HttpRouter.h/.cpp     # Route management and request handling
├── HttpParser.h          # HTTP request parsing utilities
├── responses.h           # Response generation helpers
└── README.md            # Project documentation
```

## 🚀 Quick Start

### Prerequisites

- **C++17** compatible compiler (MSVC, MinGW)
- **Windows SDK** (for WinSock2)
- **jwt-cpp** library

### Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/yourusername/cpp-socket-api-server.git
   cd cpp-socket-api-server
   ```

2. **Install jwt-cpp**
   ```bash
   # Using vcpkg (recommended)
   vcpkg install jwt-cpp
   
   # Or download headers manually
   # https://github.com/Thalhammer/jwt-cpp
   ```

3. **Build and Run**
   ```bash
   # Using Visual Studio
   # Or compile manually:
   g++ -std=c++17 main.cpp HttpRouter.cpp -lws2_32 -o server.exe
   ./server.exe
   ```

4. **Test the server**
   ```bash
   curl http://localhost:8080/
   ```

## 📡 API Endpoints

### Public Endpoints
```http
GET  /                    # Welcome page
GET  /index.html         # Same as root
POST /login              # Authenticate user
```

### Protected Endpoints (Requires JWT)
```http
GET  /api/user/ID        # Get user information
```

## 🔐 Authentication

The server uses **JWT (JSON Web Tokens)** for authentication:

### Login Request
```bash
curl -X POST http://localhost:8080/login \
  -H "Content-Type: application/x-www-form-urlencoded" \
  -d "username=admin&password=password"
```

### Response
```json
{
  "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9...",
  "type": "Bearer"
}
```

### Using Protected Endpoints
```bash
curl http://localhost:8080/api/user/ID \
  -H "Authorization: Bearer YOUR_JWT_TOKEN"
```

## 🏗️ Architecture

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

## 🧪 Testing

### Manual Testing
```bash
# Test welcome page
curl http://localhost:8080/

# Test API endpoint (should return 401)
curl http://localhost:8080/api/user/ID

# Login and get token
curl -X POST http://localhost:8080/login -d "username=admin"

# Use token for protected endpoint
curl -H "Authorization: Bearer TOKEN" http://localhost:8080/api/user/ID
```

### Adding New Routes
```cpp
// In HttpRouter constructor
routes["GET /api/users"] = [](const ParsedRequest& req) {
    return buildJSONResponse("{\"users\":[]}");
};

// Protected route
addProtectedRoute("POST /api/data", [](const ParsedRequest& req) {
    return buildJSONResponse("{\"success\":true}");
});
```

## 📈 Performance

- **Lightweight**: No heavy frameworks, minimal memory footprint
- **Fast**: Direct socket handling without abstraction layers
- **Concurrent**: Handles multiple client connections
- **Scalable**: Easy to extend with connection pooling

## 🛡️ Security Features

- **JWT Token Validation** - Cryptographic signature verification
- **Request Size Limits** - Buffer overflow protection
- **Input Sanitization** - Safe string handling
- **Connection Timeouts** - DoS protection

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add some amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 👨‍💻 Author

**Your Name**
- GitHub: [@yourusername](https://github.com/yourusername)
- LinkedIn: [Your LinkedIn](https://linkedin.com/in/yourprofile)

## 🙏 Acknowledgments

- [jwt-cpp](https://github.com/Thalhammer/jwt-cpp) - JWT library for C++
- Microsoft WinSock2 - Windows networking API
- C++ Standard Library - Modern C++ features

---

⭐ **Star this repo** if you find it helpful!
