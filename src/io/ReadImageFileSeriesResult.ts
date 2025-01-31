import Image from '../core/Image.js'
import WorkerPool from '../core/WorkerPool.js'

interface ReadImageFileSeriesResult {
  image: Image
  webWorkerPool: WorkerPool
}

export default ReadImageFileSeriesResult
