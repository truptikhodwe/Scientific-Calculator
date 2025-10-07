// pipeline {
//     agent any // Run on any available Jenkins agent
//     environment {
//         // IMPORTANT: Replace <your_dockerhub_username> with your actual username
//         DOCKER_USERNAME = "trupti1812"
//         DOCKER_CREDENTIALS_ID = "dockerhub-credentials" // The ID you set in Jenkins
//     }
//     stages {
//         stage('Checkout from GitHub') {
//             steps {
//                 git 'https://github.com/truptikhodwe/Scientific-Calculator.git'
//             }
//         }
//         stage('Run Tests') {
//             steps {
//                 // We run the tests inside a temporary Docker container to match the build environment
//                 // This command mounts the project folder into a container and runs 'make test'
//                 sh "docker run --rm -v ${pwd()}:/app -w /app gcc:latest bash -c 'apt-get update && apt-get install -y libgtest-dev cmake && cd /usr/src/gtest && cmake CMakeLists.txt && make && cp lib/*.a /usr/lib && cd /app && make test'"
//             }
//         }
//         stage('Build Docker Image') {
//             steps {
//                 sh "docker build -t ${DOCKER_USERNAME}/scientific-calculator:latest ."
//             }
//         }
//         stage('Push to Docker Hub') {
//             steps {
//                 // Jenkins will use the stored credentials to log in and push
//                 withCredentials([usernamePassword(credentialsId: DOCKER_CREDENTIALS_ID, usernameVariable: 'USER', passwordVariable: 'PASS')]) {
//                     sh "echo ${PASS} | docker login -u ${USER} --password-stdin"
//                     sh "docker push ${DOCKER_USERNAME}/scientific-calculator:latest"
//                     sh "docker logout"
//                 }
//             }
//         }
//         stage('Deploy with Ansible') {
//             steps {
//                 // Jenkins runs the Ansible command to deploy the new container
//                 sh "ansible-playbook playbook.yml -i inventory.ini -e 'docker_username=${DOCKER_USERNAME}'"
//             }
//         }
//     }
// }
pipeline {
    agent any
    environment {
         DOCKER_USERNAME = "trupti1812"
         DOCKER_CREDENTIALS_ID = "dockerhub-credentials"
    }
    stages {
        // The extra checkout stage has been removed.
        // Jenkins automatically checks out the code before the stages begin.

        stage('Run Tests') {
            steps {
                sh "docker run --rm -v ${pwd()}:/app -w /app gcc:latest bash -c 'apt-get update && apt-get install -y libgtest-dev cmake && cd /usr/src/gtest && cmake CMakeLists.txt && make && cp lib/*.a /usr/lib && cd /app && make test'"
            }
        }
        stage('Build Docker Image') {
            steps {
                sh "docker build -t ${DOCKER_USERNAME}/scientific-calculator:latest ."
            }
        }
        stage('Push to Docker Hub') {
            steps {
                withCredentials([usernamePassword(credentialsId: DOCKER_CREDENTIALS_ID, usernameVariable: 'USER', passwordVariable: 'PASS')]) {
                    sh "echo ${PASS} | docker login -u ${USER} --password-stdin"
                    sh "docker push ${DOCKER_USERNAME}/scientific-calculator:latest"
                    sh "docker logout"
                }
            }
        }
        stage('Deploy with Ansible') {
            steps {
                sh "ansible-playbook playbook.yml -i inventory.ini -e 'docker_username=${DOCKER_USERNAME}'"
            }
        }
    }
}