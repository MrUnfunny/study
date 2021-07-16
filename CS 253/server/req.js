const net = require('net')

// small program to create GET request manually
const socket = net.createConnection({
    host: 'example.com',
    port: 80
})

const request = `GET / HTTP/1.1
Host: example.com

`

socket.write(request)

socket.pipe(process.stdout)