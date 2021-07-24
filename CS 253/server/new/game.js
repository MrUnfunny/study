const express = require('express')
const bodyParser = require('body-parser')

const app = express()


app.get('/', (req, res) => {
    res.sendFile(__dirname + '/new.html')
})

app.listen(3000, () => {
    console.log('listening')
})