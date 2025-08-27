
def sendMail() {
    mail bcc: '',
     body: "<b>Example</b><br>Project: ${env.JOB_NAME} <br>Build Number: ${env.BUILD_NUMBER} <br> URL: <a href = ${env.BUILD_URL}>${env.BUILD_URL}</a>",
     cc: '',
     charset: 'UTF-8',
     from: 'pth@embc.no',
     mimeType: 'text/html',
     replyTo:   'noreply@logmaster-jenkins',
     subject:   "${currentBuild.result} CI: Project name -> ${env.JOB_NAME}",
     to: 'pth@embc.no'
}

pipeline
{
    agent any

    stages
    {
        stage('Build')
        {
            stages
            {
                stage('Create docker image')
                {
                    steps
                    {
                        dir('docker-cross')
                        {
                            sh 'whoami'
                            sh './create-image.sh'
                        }
                    }
                }
                stage('X86-compile')
                {
                    steps
                    {
                        sh   './scripts/host/compile.sh x86'
                    }
                }
                stage('ARM-compile')
                {
                    steps
                    {
                        sh   './scripts/host/compile.sh arm'
                    }
                }
            }
        }
            stages
            {
            stage('X86-unittests')
            {
                steps
                {
                    sh './scripts/host/run-tests.sh x86'
                }
            }
            }
    }
    post {
        always {
            sendMail()
        }
        success {
            sendMail()
        }
        failure {
            sendMail()
        }
        unstable {
        }
        changed {
            sendMail()
        }
    }

}
