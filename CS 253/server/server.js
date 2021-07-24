const express = require('express')
const { createReadStream } = require('fs')
const bodyParser = require('body-parser')
const cookieParser = require('cookie-parser')
const randomBytes = require('crypto').randomBytes

//demo server for learning about cookies

const db = {
    'alice': 'password',
    'bob': 'password2'
}

const sessions = {}

const app = express()

app.use(cookieParser())
app.use(bodyParser.urlencoded({ extended: false }))

app.get('/', (req, res) => {

    console.log('getting started')
    const sessionId = req.cookies.sessionId
    if (sessions[sessionId] === undefined || sessionId === undefined) {
        createReadStream(__dirname + '/html/home.html').pipe(res)
    } else {
        res.send(`Hey there, ${sessions[sessionId]}`)
    }
})

app.post('/login', (req, res) => {
    const username = req.body.username
    const password = req.body.password

    const sessionId = randomBytes(16).toString('base64')

    sessions[sessionId] = username

    if (db[username] === password) {
        res.cookie('sessionId', sessionId,)
        res.send(`Hey there, ${req.body.username}`)
    }
    else {
        res.send('Login Failed  ')
    }
})

app.get('/logout', (req, res) => {
    const sessionId = req.cookies.sessionId
    res.clearCookie('sessionId')
    delete sessions[sessionId]
    res.redirect('/')
})

app.listen(3000, () => {
    console.log('Server running on port 3000')
})