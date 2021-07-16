const express = require('express')
const { createReadStream } = require('fs')
const bodyParser = require('body-parser')
const cookieParser = require('cookie-parser')

//demo server for learning about cookies

const db = {
    'alice': 'password',
    'bob': 'password2'
}

const app = express()

app.use(cookieParser())
app.use(bodyParser.urlencoded({ extended: false }))

app.get('/', (req, res) => {

    console.log('getting started')
    const username = req.cookies.username
    console.log(username)
    if (db[username] === undefined || username === undefined) {
        createReadStream(__dirname + '/html/home.html').pipe(res)
    } else {
        res.send(`Hey there, ${username}`)
    }
})

app.get('/cool', (req, res) => {
    const username = 'cool'
    console.log('getting started')
    res.send(`Hey there, ${username}`)

})

app.post('/login', (req, res) => {
    const username = req.body.username
    const password = req.body.password

    if (db[username] === password) {
        res.cookie('username', username)
        res.send(`Hey there, ${req.body.username}`)
    }
    else {
        res.send('Login Failed  ')
    }
})

app.listen(3000, () => {
    console.log('Server running on port 3000')
})