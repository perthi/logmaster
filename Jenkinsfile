
pipeline
{
    agent any
    {
		stage("Build compiler docker image")
		{
				dir("docker-cross2")
				{
					sh './create-image.sh'
				}
		}
	}
}