
pipeline
{
    agent any

	stages
	{	
		stage("Build compiler docker image")
		{
			steps
			{
				dir("docker-cross")
				{
					sh './create-image.sh'
				}
			}
		}
	}

}